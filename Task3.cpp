// tic_tac_toe.cpp
#include <iostream>
using namespace std;

char board[3][3];
char currentPlayer = 'X';

void initializeBoard() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            board[i][j] = '1' + (i * 3 + j);
}

void printBoard() {
    cout << "\n";
    for (int i = 0; i < 3; i++) {
        cout << " ";
        for (int j = 0; j < 3; j++) {
            cout << board[i][j];
            if (j < 2) cout << " | ";
        }
        cout << "\n";
        if (i < 2) cout << "---+---+---\n";
    }
    cout << "\n";
}

bool isWin() {
    for (int i = 0; i < 3; i++)
        if ((board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer) ||
            (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer))
            return true;

    if ((board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer) ||
        (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer))
        return true;

    return false;
}

bool isDraw() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] != 'X' && board[i][j] != 'O')
                return false;
    return true;
}

void switchPlayer() {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

void playGame() {
    string playAgain;
    do {
        initializeBoard();
        currentPlayer = 'X';
        bool gameOver = false;

        while (!gameOver) {
            printBoard();
            int move;
            cout << "Player " << currentPlayer << ", enter your move (1-9): ";
            cin >> move;

            int row = (move - 1) / 3;
            int col = (move - 1) % 3;

            if (move >= 1 && move <= 9 && board[row][col] != 'X' && board[row][col] != 'O') {
                board[row][col] = currentPlayer;

                if (isWin()) {
                    printBoard();
                    cout << "Player " << currentPlayer << " wins!\n";
                    gameOver = true;
                } else if (isDraw()) {
                    printBoard();
                    cout << "It's a draw!\n";
                    gameOver = true;
                } else {
                    switchPlayer();
                }
            } else {
                cout << "Invalid move, try again.\n";
            }
        }

        cout << "Play again? (yes/no): ";
        cin >> playAgain;
    } while (playAgain == "yes");

    cout << "Thank you for playing!\n";
}

int main() {
    playGame();
    return 0;
}
