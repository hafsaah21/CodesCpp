#include <iostream>
#include <vector>

using namespace std;

void printBoard(const vector<vector<char>>& board) {
    cout << "    |     |    " << endl;
    cout << " " << board[0][0] << "  |  " << board[0][1] << "  |  " << board[0][2] << endl;
    cout << "____|_____|____" << endl;
    cout << "    |     |    " << endl;
    cout << " " << board[1][0] << "  |  " << board[1][1] << "  |  " << board[1][2] << endl;
    cout << "____|_____|____" << endl;
    cout << "    |     |    " << endl;
    cout << " " << board[2][0] << "  |  " << board[2][1] << "  |  " << board[2][2] << endl;
    cout << "    |     |    " << endl;
}

bool checkWin(const vector<vector<char>>& board, char player) {
    for (int i = 0; i < 3; ++i) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return true;
        }
    }
    return ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
            (board[0][2] == player && board[1][1] == player && board[2][0] == player));
}

bool checkDraw(const vector<vector<char>>& board) {
    for (const auto& row : board) {
        for (char cell : row) {
            if (cell != 'X' && cell != 'O') {
                return false;
            }
        }
    }
    return true;
}

int main() {
    vector<vector<char>> board = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
    char currentPlayer = 'X';
    bool gameWon = false;

    do {
        printBoard(board);
        int move;
        cout << "Player " << currentPlayer << ", enter your move: ";
        cin >> move;
        if (move < 1 || move > 9) {
            cout << "Invalid move! Please choose a number between 1 and 9." << endl;
            continue;
        }
        int row = (move - 1) / 3;
        int col = (move - 1) % 3;
        if (board[row][col] == 'X' || board[row][col] == 'O') {
            cout << "That cell is already occupied! Try again." << endl;
            continue;
        }
        board[row][col] = currentPlayer;

        if (checkWin(board, currentPlayer)) {
            gameWon = true;
            cout << "Player " << currentPlayer << " wins!" << endl;
        } else if (checkDraw(board)) {
            cout << "It's a draw!" << endl;
            break;
        }

        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    } while (!gameWon);

    printBoard(board);

    char playAgain;
    cout << "Do you want to play another game? (Y/N): ";
    cin >> playAgain;

    if (playAgain == 'Y' || playAgain == 'y') {
        main(); 
    }

    return 0;
}
