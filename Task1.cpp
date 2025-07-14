// number_guessing_game.cpp
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    srand(time(0));  // Initialize random seed
    int number = rand() % 100 + 1; // Random number between 1 and 100
    int guess, attempts = 0;

    cout << "Welcome to Number Guessing Game!\n";
    cout << "Guess the number between 1 and 100:\n";

    do {
        cout << "Enter your guess: ";
        cin >> guess;
        attempts++;

        if (guess > number) {
            cout << "Too high! Try again.\n";
        } else if (guess < number) {
            cout << "Too low! Try again.\n";
        } else {
            cout << "Congratulations! You guessed it in " << attempts << " attempts.\n";
        }
    } while (guess != number);

    return 0;
}
