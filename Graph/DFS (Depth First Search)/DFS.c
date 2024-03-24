#include <stdio.h>

void dfs(int g[5][5], int start, int visited[5]) {
    printf("%d ", start);
    visited[start] = 1;

    for (int i = 0; i < 5; i++) {
        if (g[start][i] == 1 && !visited[i]) {
            dfs(g, i, visited);
        }
    }
}

int main() {
    int g[5][5] = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 1, 0},
        {1, 1, 0, 0, 1},
        {0, 1, 0, 0, 1},
        {0, 0, 1, 1, 0}
    };
    int visited[5] = {0};

    dfs(g, 0, visited);

    return 0;
}

/*
Output:
0 1 2 4 3
*/