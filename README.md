# 🧱 Pong Game in C++ with Design Patterns

This is a complete, professional implementation of a **Pong-style game** built using **C++17** and **SDL2**, with a deliberate focus on learning and applying **Software Design Patterns** in a fun, gamified way.

> 🎯 Learn software architecture by building a real game — one pattern at a time.

---

## 🚀 Features

- 🧠 Teaches **6 major design patterns** through implementation
- 🎮 Game states: Menu, Playing, Game Over
- 🏗️ Brick destruction and score system
- 🕹️ Paddle movement with key commands
- 🔔 HUD rendering and live updates
- 💡 Fully modular and extensible codebase

---

## 🧰 Requirements

> Works on macOS, Linux, and Windows (via WSL or MSYS2)

- **C++17 compiler** (`g++` or `clang++`)
- **SDL2** installed

### 🛠️ macOS

```bash
brew install sdl2
```

### 🛠️ Linux

```bash
sudo apt-get install libsdl2-dev
```

### 🛠️ Windows

Use MSYS2 or WSL and install SDL2 via package manager.

---

## 📦 Folder Structure

```
pong-patterns/
├── include/               # Header files
├── src/                   # Source files
├── build/                 # Compiled binary output
├── assets/                # Game assets (future)
├── Makefile               # Build configuration
└── README.md              # This documentation
```

---

## 🏁 How to Build and Run

### 1. Clone the repository

```bash
git clone https://github.com/Manuelmj123/Pong-Patterns.git
cd pong-patterns
```

### 2. Build the game

```bash
make
```

### 3. Run it

```bash
./build/pong
```

---

## 🎮 Controls

| Key       | Action              |
|-----------|---------------------|
| ⬅️ Left    | Move paddle left     |
| ➡️ Right   | Move paddle right    |
| ⏎ Enter    | Start game           |
| ⎋ Escape   | Quit game            |

---

## 🧩 Design Patterns Breakdown

| Pattern       | Used In                         | Description |
|---------------|----------------------------------|-------------|
| **Singleton** | `Game` class                     | Ensures single instance of main game controller |
| **State**     | `MenuState`, `PlayState`, `GameOverState` | Manages switching between states cleanly |
| **Command**   | `MoveLeftCommand`, `MoveRightCommand` | Decouples input from game logic |
| **Factory**   | `GameObjectFactory`              | Creates paddles, balls, bricks dynamically |
| **Observer**  | `ScoreManager` + `HUD`           | HUD updates automatically on score changes |
| **Strategy**  | `Ball::update()` using Paddle    | Swappable behavior for ball bounce (extension point) |

---

## 🧠 What You Learned (Step-by-Step Recap)

### ✅ Singleton Pattern

- Applied to `Game` class to ensure one game controller
- Accessible via `Game::getInstance()`

### ✅ State Pattern

- Abstract `GameState` base class
- Implemented `MenuState`, `PlayState`, `GameOverState`
- Seamless switching using `Game::changeState()`

### ✅ Command Pattern

- Abstract `Command` base
- Concrete `MoveLeftCommand`, `MoveRightCommand`
- `InputHandler` maps keypresses to commands

### ✅ Factory Pattern

- `GameObjectFactory::create("Paddle")` etc.
- Dynamically instantiates `Paddle`, `Ball`, `Brick`

### ✅ Observer Pattern

- `ScoreManager` notifies `HUD` via `onNotify(score)`
- Completely decouples score tracking from rendering

### ✅ Strategy Potential

- `Ball::update()` behavior influenced by `Paddle` (bounce)
- Could swap for AI paddle or different bounce physics later

---

## 🧪 Planned Future Enhancements

- Restart button in `GameOverState`
- Add sound using SDL_mixer (Observer or Strategy)
- Add animated bricks and paddle shake effect
- Local 2-player mode (additional input mapping)

---

## 👨‍💻 Author

Created by Manuel Zelaya — gamifying the process of mastering design patterns through hands-on C++ development.

---

## 📜 License

MIT License — Free for personal or commercial use.