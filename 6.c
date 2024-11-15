#include <stdio.h>

#define SIZE 3

// Function prototypes
void printBoard(char board[SIZE][SIZE]);
int checkWinner(char board[SIZE][SIZE]);
void makeMove(char board[SIZE][SIZE], int player);

int main() {
    char board[SIZE][SIZE] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
    int player = 1, winner = 0, moves = 0;

    printf("Welcome to Tic Tac Toe!\n");
    while (winner == 0 && moves < SIZE * SIZE) {
        printBoard(board);
        makeMove(board, player);
        winner = checkWinner(board);
        player = (player % 2) + 1;  // Switch player
        moves++;
    }

    printBoard(board);
    if (winner) {
        printf("Player %d wins!\n", winner);
    } else {
        printf("It's a draw!\n");
    }
    return 0;
}

void printBoard(char board[SIZE][SIZE]) {
    printf("\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf(" %c ", board[i][j]);
            if (j < SIZE - 1) printf("|");
        }
        printf("\n");
        if (i < SIZE - 1) printf("---+---+---\n");
    }
    printf("\n");
}

void makeMove(char board[SIZE][SIZE], int player) {
    int choice;
    char mark = (player == 1) ? 'X' : 'O';

    while (1) {
        printf("Player %d, enter your move (1-9): ", player);
        scanf("%d", &choice);

        if (choice >= 1 && choice <= 9) {
            int row = (choice - 1) / SIZE;
            int col = (choice - 1) % SIZE;

            if (board[row][col] != 'X' && board[row][col] != 'O') {
                board[row][col] = mark;
                break;
            } else {
                printf("Invalid move! Cell already taken.\n");
            }
        } else {
            printf("Invalid choice! Please select a number between 1 and 9.\n");
        }
    }
}

int checkWinner(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) return (board[i][0] == 'X') ? 1 : 2;
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) return (board[0][i] == 'X') ? 1 : 2;
    }

    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) return (board[0][0] == 'X') ? 1 : 2;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) return (board[0][2] == 'X') ? 1 : 2;

    return 0;
}