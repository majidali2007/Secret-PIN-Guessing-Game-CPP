# 🔐 Secret PIN Guessing Game (C++)

A console-based **Secret PIN Guessing Game** written in C++ for my Programming Fundamentals course. The computer generates a random 4-digit PIN, and you have **5 attempts** to crack it using positional hints after each guess.

---

## ✨ Features

- **Interactive Menu:** Play the game, read the rules, or exit cleanly.
- **Random 4-Digit PIN:** Generates a new PIN between `1000` and `9999` every round.
- **Positional Hints:** Reveals correctly placed digits after every wrong guess (e.g., `[ 4 ] [ _ ] [ 2 ] [ _ ]`) along with the total match count.
- **Input Validation:** Rejects numbers outside the `1000–9999` range without wasting an attempt.
- **Win/Loss Feedback:** Celebrates early wins and reveals the secret PIN if you run out of attempts.

---

## 🎮 How to Play

1. Choose **1. Play Game** from the main menu.
2. Enter a 4-digit number between `1000` and `9999`.
3. Use the positional hint to adjust your next guess.
4. Crack the PIN within **5 attempts** to win!

---

## 🛠️ C++ Concepts Used

- **Functions:** `showHeader()`, `showRules()`, and `playGame()` for modular code.
- **Randomization:** `srand(time(0))` and `rand()` from `<cstdlib>` and `<ctime>`.
- **Arrays & Digit Extraction:** Splitting 4-digit numbers into arrays using `%` and `/` for digit-by-digit comparison.
- **Loops & Control Flow:** `do-while` (menu & validation), `for` (attempts & array checks), and `switch-case` (menu navigation).

---

## 🚀 Getting Started

### Option 1: Run in Dev-C++
1. Clone or download this repository.
2. Open the `.cpp` file in **Dev-C++**.
3. Press **F11** to compile and run.

### Option 2: Run via Terminal (g++)
```bash
g++ main.cpp -o secret_pin_game
./secret_pin_game
