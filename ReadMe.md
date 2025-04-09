# Hangman Game in C++

This is a simple terminal-based Hangman game developed in C++. The player guesses letters to reveal a hidden word with a limit of 10 wrong attempts.

## 🎯 Features

- Randomly reveals one letter of the word at the start.
- Case-insensitive guessing.
- Cross-platform screen clearing.
- Input validation (only single alphabetic characters accepted).
- Modular and readable code.
- Option to replay after each round.

## 🔧 Technologies Used

- C++ (Standard Library)
- Random Number Generation (`<random>`)
- Input handling and validation

## ▶️ How to Play

1. One player inputs a word (keep it secret from the guesser).
2. The screen is cleared and one letter is revealed.
3. The guesser types one letter per turn.
4. After 10 incorrect guesses, the game ends.
5. Option to replay the game.

## 🧠 Code Highlights

- `generateRandomIndex(int length)`: Returns a random index to reveal a letter.
- `getValidLetter()`: Ensures valid user input.
- `playRound(string word)`: Core game logic.
- `clearScreen()`: Platform-safe screen clearing.

## 💻 Usage

### Compilation
```bash
g++ -o hangman hangman.cpp
