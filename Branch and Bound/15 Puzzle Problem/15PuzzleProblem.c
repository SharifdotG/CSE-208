#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define N 4

struct PuzzleState {
    int puzzle[N][N];
    int emptyRow, emptyColumn, cost;
};

int calculateHeuristic(int puzzle[N][N]) {
    int heuristic = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (puzzle[i][j] != 0) {
                int x = (puzzle[i][j] - 1) / N;
                int y = (puzzle[i][j] - 1) % N;

                heuristic += abs(x - i) + abs(y - j);
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
            printf("%d ", puzzle[i][j]);
        }

        printf("\n");
    }
}

void solvePuzzle(int initial[N][N]) {
    struct PuzzleState {
        int puzzle[N][N];
        int emptyRow, emptyColumn, cost;
    };

    struct PuzzleState initialState;
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

    struct PuzzleState pq[1000];
    int pqSize = 0;

    pq[pqSize++] = initialState;

    while (pqSize > 0) {
        int minIndex = 0;

        for (int i = 1; i < pqSize; i++) {
            if (pq[i].cost < pq[minIndex].cost) {
                minIndex = i;
            }
        }

        struct PuzzleState current = pq[minIndex];
        for (int i = minIndex; i < pqSize - 1; i++) {
            pq[i] = pq[i + 1];
        }

        pqSize--;

        if (current.cost == 0) {
            printf("Solution found!\n");
            printPuzzle(current.puzzle);

            return;
        }

        int dx[] = {0, 0, 1, -1};
        int dy[] = {1, -1, 0, 0};

        for (int i = 0; i < 4; i++) {
            int newRow = current.emptyRow + dx[i];
            int newColumn = current.emptyColumn + dy[i];

            if (newRow >= 0 && newRow < N && newColumn >= 0 && newColumn < N) {
                struct PuzzleState next = current;
                
                next.puzzle[current.emptyRow][current.emptyColumn] = next.puzzle[newRow][newColumn];
                next.puzzle[newRow][newColumn] = 0;
                next.emptyRow = newRow;
                next.emptyColumn = newColumn;
                next.cost = calculateHeuristic(next.puzzle);

                pq[pqSize++] = next;
            }
        }
    }

    printf("Solution not found!\n");
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