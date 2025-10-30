#ifndef MODEL_H
#define MODEL_H

#include <QObject>
#include <QTimer>

using std::string;

class Model : public QObject
{
    Q_OBJECT

public:

    ///
    /// \brief Model - constructor
    /// \param parent
    ///
    explicit Model(QObject *parent = nullptr);

    /// \brief Model - destructor
    ~Model();

    ///
    /// \brief enum representing button colors
    ///
    enum Button {
        RED,
        BLUE
    };

    ///
    /// \brief Enum representing game states
    ///
    enum GameStatus {
        NOT_STARTED = 0,    // Game hasn't started
        COMPUTER_TURN = 1,  // Computer is playing sequence
        PLAYER_TURN = 2,    // Player's turn to input
        GAME_OVER = 3,       // Player failed
        TWIST_TUTORIAL = 4  // Moves start disappearing - (only last 5 moves are shown)
    };

public slots:

    ///
    /// \brief blue button Pressed
    ///
    void bluePressed();

    ///
    /// \brief red buttonPressed
    ///
    void redPressed();

    ///
    /// \brief start button Pressed
    ///
    void startGame();

signals:

    ///
    /// \brief emmitRed
    ///
    void emitRed();

    ///
    /// \brief emmitBlue
    ///
    void emitBlue();

    ///
    /// \brief changeStatus - Changes the state of the game
    ///
    void changeStatus(GameStatus);

private:

    ///
    /// \brief the correct(computer) sequence of moves
    ///
    std::vector<Button> ComputerSequence;

    ///
    /// \brief status - The state the game is in.
    ///
    GameStatus status;

    ///
    /// \brief PlayerProgressIterator - This iterator points to the expected correct move the player must perform.
    ///
    unsigned int PlayerProgressIndex;

    ///
    /// \brief displayTimer - Timer that fires repeatedly in play sequence
    ///
    QTimer displayTimer;

    ///
    /// \brief Tracks which move we're showing
    ///
    int currentDisplayIndex;

    ///
    /// \brief BaseDelay
    ///
    int baseDelay;

    ///
    /// \brief tutorialShown - bool that tracks if the tutorial has been shown
    ///
    bool tutorialShown;

    ///
    /// \brief playSequence - Plays the computer sequence to the player
    ///
    void playSequence();

    ///
    /// \brief playerMove - Handle's what move the player made in real time
    /// \param buttonPlayerPressed - The button the player pressed
    ///
    void CheckPlayerMove(Button buttonPlayerPressed);

    ///
    /// \brief - Called by timer to show next move by the computer
    ///
    void displayNextMove();

    ///
    /// \brief calculateDelay - calculates delay for timing between the computer's moves being shown.
    ///
    int calculateDelay();

    ///
    /// \brief AddMove - Adds a move to the computer sequence.
    ///
    void AddMove();
};

#endif // MODEL_H
