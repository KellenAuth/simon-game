# Simon Memory Game

A modern recreation of the classic Simon electronic memory game built with C++ and Qt. Test your memory by repeating increasingly complex color sequences - but watch out! After 5 moves, you'll need to rely on your memory as only the last 5 moves are displayed.

## 🎮 About the Game

Simon is a memory game where the computer displays a sequence of colored buttons that light up. Your goal is to repeat the sequence correctly. Each round adds a new move to the sequence, making it progressively harder. One wrong move and it's game over!

This version features two buttons (Red and Blue) and implements a **memory challenge twist**: after the 5th move, only the last 5 moves are shown during the computer's turn - you must remember the earlier moves in the sequence!

## ✨ Features

### Core Gameplay
- **Two-button Simon gameplay** - Red and Blue buttons with visual feedback
- **Progressive difficulty** - Each successful round adds a new move to the sequence
- **Speed increase** - Computer playback speeds up as the sequence grows longer

### Interface
- **Smart button states** - Buttons automatically enable/disable based on game state
- **Start/restart functionality** - Clean game state management
- **Visual feedback** - Buttons flash with color changes during sequences
- **Adaptive layout** - Responsive design that scales with window resizing

### Creative Element 🌟
**Limited Sequence Display**: After move 5, the computer only displays the last 5 moves of the sequence. You must remember the earlier moves to progress! This adds a significant memory challenge beyond traditional Simon gameplay.

## 🛠️ Technologies Used

- **Language:** C++ (C++17)
- **Framework:** Qt 6 (Widgets)
- **Architecture:** Model-View design pattern with signals/slots
- **Tools:** Qt Creator, Git
- **Course:** CS 3505 - Software Practice II

## 🎯 Technical Highlights

### Architecture
- **Model-View separation** - Clean separation between game logic (`Model` class) and UI (`MainWindow`)
- **Signal/slot communication** - All Model-View communication happens through Qt's signal/slot mechanism
- **No direct references** - View and Model don't store direct references to each other

### Key Implementation Details
- `QTimer::singleShot()` for timed button flashing and sequence delays
- Dynamic stylesheet manipulation for button color changes
- Sequence randomization for move generation
- Game state management (waiting, playing, player turn, game over)

## 📦 How to Build and Run

### Prerequisites
- Qt 6.x installed
- Qt Creator (recommended) or CMake
- C++17 compatible compiler
- Git

### Clone and Run
```bash
# Clone the repository
git clone https://github.com/KellenAuth/simon-game.git
cd simon-game

# Open in Qt Creator
# 1. Open Qt Creator
# 2. File -> Open File or Project
# 3. Select the .pro file
# 4. Configure project and click "Run"
```

### Building from Command Line
```bash
qmake
make
./SimonGame  # or SimonGame.exe on Windows
```

## 🎓 What I Learned

- **Qt Framework fundamentals** - Widgets, signals/slots, event-driven programming
- **Model-View architecture** - Proper separation of concerns in GUI applications
- **Asynchronous programming** - Using timers for non-blocking delays
- **UI/UX design** - Creating responsive, intuitive game interfaces
- **State management** - Handling complex game states and transitions
- **C++ best practices** - Smart pointers, const correctness, RAII

## 🎮 How to Play

1. Click **Start Game** to begin
2. Watch the computer display the sequence (buttons will flash)
3. Repeat the sequence by clicking the buttons in order
4. Progress bar shows your completion percentage
5. Successfully complete the sequence to advance to the next round
6. **Remember:** After move 5, only the last 5 moves are shown!
7. Make a mistake? Game over! Try to beat your high score.

## 🚀 Future Improvements

- Add difficulty levels (more buttons, faster speeds)
- Implement persistent high score leaderboard
- Add sound effects for each button
- Create multiple game modes (endless, timed, challenge)
- Add colorblind-friendly mode with patterns/symbols

## 👥 Development

**Developer:** Kellen Auth & Other Student
**GitHub:** [@KellenAuth](https://github.com/KellenAuth)  
**Course:** CS 3505 - Software Practice II, University of Utah  
**Semester:** Fall 2024

## 📄 License

This project was created for educational purposes as part of CS 3505 at the University of Utah.

---

*"How good is your memory? Find out with Simon!"*
