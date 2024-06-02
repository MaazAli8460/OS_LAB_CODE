#include <iostream>
#include <unistd.h>
#include <cstdlib>

using namespace std;

int main() {
    int guess, bet_amount;

    // Read guess and bet amount from parent process
    read(STDIN_FILENO, &guess, sizeof(guess));
    read(STDIN_FILENO, &bet_amount, sizeof(bet_amount));

    // Simulate game logic
    int random_number = rand() % 10 + 1; // Generate random number between 1 and 10

    if (guess == random_number) {
        int winnings = bet_amount * 10;
        cout << "Congratulations! You guessed the correct number. You win $" << winnings << endl;
        write(STDOUT_FILENO, &winnings, sizeof(winnings)); // Send winnings to parent process
    } else {
        cout << "Sorry, you guessed the wrong number. You lose $" << bet_amount << endl;
        int loss = -bet_amount;
        write(STDOUT_FILENO, &loss, sizeof(loss)); // Send loss to parent process
    }

    return 0;
}
