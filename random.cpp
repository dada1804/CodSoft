#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    // Seed the random number generator with the current time
    srand(static_cast<unsigned int>(time(nullptr)));

    // Generate a random number between 1 and 100
    int secretNumber = rand() % 100 + 1;

    int lowerBound = 1;
    int upperBound = 100;
    int guess;
    int attempts = 0;

    cout << "Welcome to the Binary Search Number Game!" << endl;
    cout << "I have selected a random number between 1 and 100." << endl;
    cout << "Can you guess what it is?" << endl;

    do {
        // Use binary search to make a guess
        guess = (lowerBound + upperBound) / 2;
        attempts++;

        cout << "Is it " << guess << "? (1: Too low, 2: Too high, 3: Correct): ";
        int feedback;
        cin >> feedback;

        if (feedback == 1) {
            lowerBound = guess + 1;
        } else if (feedback == 2) {
            upperBound = guess - 1;
        } else if (feedback == 3) {
            cout << "Congratulations! You guessed the number (" << guess << ") in " << attempts << " attempts." << endl;
        } else {
            cout << "Invalid input. Please enter 1, 2, or 3." << endl;
        }

    } while (guess != secretNumber);

    return 0;
}
