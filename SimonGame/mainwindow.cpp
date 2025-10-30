#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "model.h"
#include <iostream>
#include <QTimer>

MainWindow::MainWindow(Model* model, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , simonGame(model)
{
    ui->setupUi(this);
    ui->twistTutorial->setVisible(false);

    // Blue button
    connect(ui->blueButton, &QPushButton::clicked, simonGame , &Model::bluePressed);
    connect(simonGame, &Model::emitBlue, this, &MainWindow::lightBlue);

    // Red button
    connect(ui->redButton, &QPushButton::clicked, simonGame , &Model::redPressed);
    connect(simonGame, &Model::emitRed, this, &MainWindow::lightRed);

    // Start button
    connect(ui->startButton, &QPushButton::clicked, simonGame , &Model::startGame);

    // Maybe have computer status to set a label up for the computer's turn
    connect(simonGame, &Model::changeStatus, this, &MainWindow::setStatus);


    // Game status changes to game over, we may want to have the color button not show up until
    // the game starts and remove access to the start button until game ends

}

MainWindow::~MainWindow()
{
    delete ui;
}

///
/// \brief MainWindow::lightBlue - makes the blue button flash blue when activated
///
void MainWindow::lightBlue(){

    QString originalStyleSheet = "background-color: rgb(0, 0, 255);";

    // change to light blue when pressed
    ui->blueButton->setStyleSheet("background-color: rgb(100, 100, 255);");

    // return to original state
    QTimer::singleShot(200, this, [this, originalStyleSheet]() {
        ui->blueButton->setStyleSheet(originalStyleSheet);
    });
}

///
/// \brief MainWindow::lightRed - makes the red button flash red when activated
///
void MainWindow::lightRed(){
    // original style sheet
    QString originalStyleSheet = "background-color: rgb(255, 0, 0);";

    // change to light red
    ui->redButton->setStyleSheet("background-color: rgb(255, 100, 100);");

    // return to original state
    QTimer::singleShot(200, this, [this, originalStyleSheet]() {
        ui->redButton->setStyleSheet(originalStyleSheet);
    });
}

///
/// \brief MainWindow::setStatus - Setting the status on the UI element
/// \param status - What status we're on
///
void MainWindow::setStatus(Model::GameStatus status){
    switch (status) {
    case Model::NOT_STARTED:
        ui->gameLabel->setText("Game Not Started");
        ui->redButton->setEnabled(false);
        ui->blueButton->setEnabled(false);
        ui->startButton->setEnabled(true);
        ui->startButton->setVisible(true);
        ui->twistTutorial->setVisible(false);
        break;
    case Model::COMPUTER_TURN:
        ui->gameLabel->setText("Wait For Sequence");
        ui->redButton->setEnabled(false);
        ui->blueButton->setEnabled(false);
        ui->startButton->setEnabled(false);
        ui->startButton->setVisible(false);
        ui->twistTutorial->setVisible(false);
        break;
    case Model::PLAYER_TURN:
        ui->gameLabel->setText("Play Sequence");
        ui->redButton->setEnabled(true);
        ui->blueButton->setEnabled(true);
        ui->startButton->setEnabled(false);
        break;
    case Model::GAME_OVER:
        ui->gameLabel->setText("Game Over");
        ui->redButton->setEnabled(false);
        ui->blueButton->setEnabled(false);
        ui->startButton->setEnabled(true);
        ui->startButton->setVisible(true);
        break;
    case Model::TWIST_TUTORIAL:
        ui->gameLabel->setText("NEW CHALLENGE!");
        ui->redButton->setEnabled(false);
        ui->blueButton->setEnabled(false);
        ui->startButton->setEnabled(false);
        ui->startButton->setVisible(false);
        ui->twistTutorial->setVisible(true);

        ui->twistTutorial->setText(
            "<h2>Memory Challenge Unlocked!</h2>"
            "<p>From now on, only the <b>last 5 moves</b> will be shown.</p>"
            "<p>You must remember the earlier moves!</p>"
            "<p>Good Luck!</p>"
            );
        break;
    default:
        ui->gameLabel->setText("Something went wrong");
        break;
    }
}
