#include <iostream>
#include <vector>
using namespace std;

bool isValid(vector<vector<char>> &board, int row, int col, char ch) {
    for(int i = 0; i < 9; i++) {
        if(board[row][i] == ch) return false;
        if(board[i][col] == ch) return false;
        if(board[3 * (row / 3) + i % 3][3 * (col / 3) + i / 3] == ch) return false;
    }
    return true;
}

bool solve(vector<vector<char>> &board) {
    for(int i = 0; i < board.size(); i++) {
        for(int j = 0; j < board[0].size(); j++) {
            if(board[i][j] == '.') {
                for(char ch = '1'; ch <= '9'; ch++) {
                    if(isValid(board, i, j, ch)) {
                        board[i][j] = ch;
                        if(solve(board)) return true;
                        board[i][j] = '.';
                    }
                }
                return false;
            }
        }
    }
    return true;
}

void solveSudoku(vector<vector<char>> &board) {
    solve(board);
}

int main() {
    vector<vector<char>> board(9, vector<char>(9));
    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            cin >> board[i][j];
        }
    }

    solveSudoku(board);

    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
