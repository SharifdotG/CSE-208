#include <stdio.h>
#include <stdbool.h>

void bfs(int g[5][5], int start) {
    int queue[5];
    bool visited[5] = {false};
    int front = 0, rear = 0;

    queue[rear++] = start;
    visited[start] = true;

    while (front < rear) {
        int node = queue[front++];

        printf("%d ", node);

        for (int i = 0; i < 5; i++) {
            if (g[node][i] == 1 && !visited[i]) {
                queue[rear++] = i;
                visited[i] = true;
            }
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

    bfs(g, 0);

    return 0;
}


/*
Output:
0 1 2 3 4
*/