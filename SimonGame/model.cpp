#include "model.h"
#include <vector>
#include <QTimer>
#include <QRandomGenerator>

using std::vector;

Model::Model(QObject *parent)
    : QObject(parent)
    , status(NOT_STARTED)
    , PlayerProgressIndex(0)
    , currentDisplayIndex(0)
    , baseDelay(900)
    , tutorialShown(false)
{
    //Connect the timer to a slot that will show the next move
    connect(&displayTimer, &QTimer::timeout, this, &Model::displayNextMove);
}

Model::~Model()=default;


void Model::bluePressed(){
    //check what state we are in
    if(status != PLAYER_TURN)
        return;

    //flash blue
    emit emitBlue();

    CheckPlayerMove(BLUE);
}

void Model::redPressed(){
    // Check if player turn
    if(status != PLAYER_TURN)
        return;

    emit emitRed();

    CheckPlayerMove(RED);
}

void Model::playSequence(){

    //add a move to computer sequence
    AddMove();

    if(ComputerSequence.size() > 5 ){
        if(!tutorialShown)
        {
            tutorialShown = true;
            status = TWIST_TUTORIAL;
            emit changeStatus(status);

            // Show tutorial for 10 seconds, THEN continue
            QTimer::singleShot(10000, this, [this]() {
                // After 10 seconds, switch back to computer turn
                status = COMPUTER_TURN;
                emit changeStatus(status);

                // Start showing the sequence
                currentDisplayIndex = ComputerSequence.size() - 5;

                int delay = calculateDelay();
                displayTimer.start(delay);
            });
            //don't start the sequence yet
            return;
        }
        currentDisplayIndex = ComputerSequence.size() - 5;
    }
    else{
        currentDisplayIndex = 0;
    }

    // Calculate delay based on computer sequence length
    int delay = calculateDelay();

    // Start the timer - it will fire every amount delay calculates
    displayTimer.start(delay);
}

void Model::startGame(){
    //change status
    status = COMPUTER_TURN;

    //play sequence
    QTimer::singleShot(300, this, [this]()
    {
        playSequence();
        emit changeStatus(status);
    });
}

void Model::AddMove(){
    // Generate random 0 or 1 using Qt's random generator
    int randomValue = QRandomGenerator::global()->bounded(2);
    Button randomButton = static_cast<Button>(randomValue);
    ComputerSequence.push_back(randomButton);
}


void Model::CheckPlayerMove(Button playerMove)
{
    if(ComputerSequence[PlayerProgressIndex] != playerMove)
    {
        status = GAME_OVER;
        tutorialShown = false;
        emit changeStatus(status);

        ComputerSequence.clear();
        PlayerProgressIndex = 0;
        currentDisplayIndex = 0;
    }
    else
    {
        PlayerProgressIndex++;
        if(ComputerSequence.size() == PlayerProgressIndex)
        {
            PlayerProgressIndex = 0;

            status = COMPUTER_TURN;
            QTimer::singleShot(1000, this, [this]()
            {
                playSequence();
                emit changeStatus(status);
            });

        }
    }
}

void Model::displayNextMove()
{
    if(currentDisplayIndex >= static_cast<int>(ComputerSequence.size()))
    {
        // done showing moves
        displayTimer.stop();
        currentDisplayIndex = 0;

        status = PLAYER_TURN;
        QTimer::singleShot(300, this, [this]()
        {
            emit changeStatus(status);
        });
        return;
    }

    // Show the current move
    if(ComputerSequence[currentDisplayIndex] == RED)
    {
        emit emitRed();
    }
    else
    {
        emit emitBlue();
    }

    // Move to the next move
    currentDisplayIndex++;
}

int Model::calculateDelay(){
    int reduction = ComputerSequence.size() * 100;
    int delay = baseDelay - reduction;
    if (delay <= 400)
        return 400;
    return delay;
}




