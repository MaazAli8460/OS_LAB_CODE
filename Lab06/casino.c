#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_PLAYERS 10
#define MAX_BET_AMOUNT 100

int main() {
    int group_amount = 0;
    int num_players;

    printf("Enter the number of players (max %d): ", MAX_PLAYERS);
    scanf("%d", &num_players);

    if (num_players < 1 || num_players > MAX_PLAYERS) {
        printf("Invalid number of players.\n");
        return 1;
    }

    // Create pipes for communication
    int pipes[num_players][2]; // [0] for reading, [1] for writing

    for (int i = 0; i < num_players; i++) {
        if (pipe(pipes[i]) == -1) {
            perror("pipe");
            exit(1);
        }
    }

    // Create child processes
    for (int i = 0; i < num_players; i++) {
        pid_t pid = fork();
        if (pid < 0) {
            perror("fork");
            exit(1);
        } else if (pid == 0) { // Child process
            close(pipes[i][0]); // Close reading end of the pipe
            // Execute child logic
            execl("./child", "child", NULL); // Replace child process with executable
            perror("execl"); // execl doesn't return if successful
            exit(1);
        }
    }

    // Parent process
    close(pipes[0][1]); // Close writing end of the first pipe

    // Game loop
    while (1) {
        int guess, bet_amount;

        printf("Enter your guess (1-10) and betting amount: ");
        scanf("%d %d", &guess, &bet_amount);

        if (guess < 1 || guess > 10 || bet_amount < 0 || bet_amount > MAX_BET_AMOUNT) {
            printf("Invalid input.\n");
            continue;
        }

        // Broadcast guess and bet amount to all players
        for (int i = 0; i < num_players; i++) {
            write(pipes[i][1], &guess, sizeof(guess));
            write(pipes[i][1], &bet_amount, sizeof(bet_amount));
        }

        // Collect results from players
        int result;
        for (int i = 0; i < num_players; i++) {
            read(pipes[i][0], &result, sizeof(result));
            group_amount += result;
        }

        printf("Group amount: %d\n", group_amount);
    }

    // Clean up pipes
    for (int i = 0; i < num_players; i++) {
        close(pipes[i][0]);
        close(pipes[i][1]);
    }

    // Wait for child processes to finish
    for (int i = 0; i < num_players; i++) {
        wait(NULL);
    }

    return 0;
}
