#include <bits/stdc++.h>

using namespace std;

bool isSafe(int board[10][10], int row, int column, int n) {
    for (int i = 0; i < row; i++) {
        if (board[i][column] == 1) {
            return false;
        }
    }

    for (int i = row, j = column; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    for (int i = row, j = column; i >= 0 && j < n; i--, j++) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    return true;
}

bool solveNQueens(int board[10][10], int row, int n) {
    if (row == n) {
        return true;
    }

    for (int column = 0; column < n; column++) {
        if (isSafe(board, row, column, n)) {
            board[row][column] = 1;

            if (solveNQueens(board, row + 1, n)) {
                return true;
            }
            
            board[row][column] = 0;
        }
    }

    return false;
}

int main() {
    int n;
    cin >> n;

    int board[10][10] = {0};

    if (solveNQueens(board, 0, n)) {
        cout << "The solution is: " << endl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << board[i][j] << " ";
            }

            cout << endl;
        }
    } else {
        cout << "Solution does not exist!" << endl;
    }

    return 0;
}

/*
Input:
4

Output:
The solution is:
0 1 0 0
0 0 0 1
1 0 0 0
0 0 1 0
*/