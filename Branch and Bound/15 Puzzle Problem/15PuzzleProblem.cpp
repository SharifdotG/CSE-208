#include <bits/stdc++.h>

using namespace std;

#define N 4

struct PuzzleState {
    int puzzle[N][N];
    int emptyRow, emptyColumn, cost;
    
    bool operator<(const PuzzleState &p) const {
        return cost > p.cost;
    }
};

int calculateHeuristic(int puzzle[N][N]) {
    int heuristic = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (puzzle[i][j] != 0) {
                int targetRow = (puzzle[i][j] - 1) / N;
                int targetColumn = (puzzle[i][j] - 1) % N;

                heuristic += abs(targetRow - i) + abs(targetColumn - j);
            }
        }
    }

    return heuristic;
}


bool isGoalState(int puzzle[N][N]) {
    int k = 1;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (k == N * N) {
                k = 0;
            }

            if (puzzle[i][j] != k++) {
                return false;
            }
        }
    }

    return true;
}

void printPuzzle(int puzzle[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << puzzle[i][j] << " ";
        }

        cout << endl;
    }
}

void solvePuzzle(int initial[N][N]) {
    priority_queue<PuzzleState> pq;

    PuzzleState initialState;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            initialState.puzzle[i][j] = initial[i][j];

            if (initial[i][j] == 0) {
                initialState.emptyRow = i;
                initialState.emptyColumn = j;
            }
        }
    }

    initialState.cost = calculateHeuristic(initialState.puzzle);

    pq.push(initialState);

    while (!pq.empty()) {
        PuzzleState current = pq.top();
        pq.pop();

        if (current.cost == 0) {
            cout << "Solution found!" << endl;
            printPuzzle(current.puzzle);

            return;
        }

        int dx[] = {0, 0, 1, -1};
        int dy[] = {1, -1, 0, 0};

        for (int i = 0; i < 4; i++) {
            int newRow = current.emptyRow + dx[i];
            int newColumn = current.emptyColumn + dy[i];

            if (newRow >= 0 && newRow < N && newColumn >= 0 && newColumn < N) {
                PuzzleState next = current;
                
                swap(next.puzzle[current.emptyRow][current.emptyColumn], next.puzzle[newRow][newColumn]);
                
                next.emptyRow = newRow;
                next.emptyColumn = newColumn;
                next.cost = calculateHeuristic(next.puzzle);

                pq.push(next);
            }
        }
    }

    cout << "Solution not found!" << endl;
}

int main() {
    int initial[N][N] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 0, 15}
    };

    solvePuzzle(initial);

    return 0;
}

/*
Input:
None

Output:
Solution found!
1 2 3 4 
5 6 7 8 
9 10 11 12
13 14 15 0
*/