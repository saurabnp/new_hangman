#include <iostream>
#include <string>
#include <random>
#include <limits> // for input validation
#include <cctype> // for tolower
using namespace std;

// Function to clear screen safely
void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

// Function to generate a random index within a given range
int generateRandomIndex(int length) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distr(0, length - 1);
    return distr(gen);
}

// Function to initialize the game state
string initializeGame(const string& word, string& guessed_word) {
    int length = word.length();
    guessed_word = string(length, '_');
    int revealIndex = generateRandomIndex(length);
    guessed_word[revealIndex] = word[revealIndex];
    return guessed_word;
}

// Function to display game instructions
void displayInstructions(const string& guessed_word) {
    cout << guessed_word;
    cout << "\nThe game starts !!!";
    cout << "\nYou have 10 wrong tries. Good luck!\n";
}

// Function to get a valid letter input from user
char getValidLetter() {
    string input;
    while (true) {
        cout << "\nGuess a letter: ";
        cin >> input;
        if (input.length() == 1 && isalpha(input[0])) {
            return tolower(input[0]);
        }
        cout << "Invalid input. Please enter a single alphabetic character." << endl;
    }
}

// Function to play a single game round
bool playRound(const string& word) {
    string guessed_word;
    initializeGame(word, guessed_word);
    displayInstructions(guessed_word);

    int wrong_tries = 0;
    while (wrong_tries < 10) {
        char guess = getValidLetter();
        bool found = false;

        for (size_t i = 0; i < word.length(); i++) {
            if (tolower(word[i]) == guess) {
                guessed_word[i] = word[i];
                found = true;
            }
        }

        if (!found) {
            cout << "Wrong guess!" << endl;
            wrong_tries++;
        }

        cout << guessed_word << endl;

        if (guessed_word == word) {
            cout << "Congratulations! You guessed the word: " << guessed_word << endl;
            return true;
        }
    }
    cout << "\nGame Over! You've used all your tries." << endl;
    cout << "The word was: " << word << endl;
    return false;
}

int main() {
    while (true) {
        string word;
        cout << "\nEnter a word (Don't show it to the guesser!): ";
        cin >> word;
        clearScreen();

        playRound(word);

        cout << "\nDo you want to play again? (Y/y to replay): ";
        char replay;
        cin >> replay;
        if (tolower(replay) != 'y') {
            break;
        }
    }
    cout << "\nThanks for playing!" << endl;
    return 0;
}