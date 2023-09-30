#include <iostream>
#include <vector>

using namespace std;

void displayBoard(const vector<vector<char>>& board) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << board[i][j];
            if (j < 2) cout << " | ";
        }
        cout << endl;
        if (i < 2) cout << "---------" << endl;
    }
}

bool checkWin(const vector<vector<char>>& board, char player) {
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) return true;  // Check rows
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) return true;  // Check columns
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) return true;      // Check diagonal
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) return true;      // Check reverse diagonal
    return false;
}

bool checkDraw(const vector<vector<char>>& board) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == ' ') return false; // If any cell is empty, the game is not a draw
        }
    }
    return true;
}

int main() {
    cout << "Welcome to Tic-Tac-Toe!" << endl;

    do {
        vector<vector<char>> board(3, vector<char>(3, ' '));
        char currentPlayer = 'X';
        bool gameWon = false;

        do {
            // Display the board
            cout << "Current board:" << endl;
            displayBoard(board);

            int row, col;
            do {
                cout << "Player " << currentPlayer << ", enter your move (row and column): ";
                cin >> row >> col;
            } while (row < 0 || row >= 3 || col < 0 || col >= 3 || board[row][col] != ' ');

            // Update the board
            board[row][col] = currentPlayer;

            // Check for a win
            if (checkWin(board, currentPlayer)) {
                gameWon = true;
                cout << "Player " << currentPlayer << " wins!" << endl;
            } else if (checkDraw(board)) {
                cout << "It's a draw!" << endl;
                break;
            }

            // Switch players
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';

        } while (!gameWon);

        // Display the final board
        cout << "Final board:" << endl;
        displayBoard(board);

        // Ask if they want to play again
        char playAgain;
        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;

        if (playAgain != 'y' && playAgain != 'Y') {
            cout << "Thank you for playing Tic-Tac-Toe!" << endl;
            break;  // Exit the game loop if not playing again
        }

    } while (true);

    return 0;
}
