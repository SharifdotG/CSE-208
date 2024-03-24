#include <stdio.h>
#include <stdbool.h>

#define V 5 // Change the value of V according to the number of vertices in the graph

void bfs(int graph[V][V], int start) {
    int queue[V];
    bool visited[V] = {false};
    int front = 0, rear = 0;

    queue[rear++] = start;
    visited[start] = true;

    while (front < rear) {
        int node = queue[front++];

        printf("%d ", node);

        for (int i = 0; i < V; i++) {
            if (graph[node][i] == 1 && !visited[i]) {
                queue[rear++] = i;
                visited[i] = true;
            }
        }
    }
}

int main() {
    int graph[V][V] = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 1, 0},
        {1, 1, 0, 0, 1},
        {0, 1, 0, 0, 1},
        {0, 0, 1, 1, 0}
    };

    bfs(graph, 0);

    return 0;
}


/*
Output:
0 1 2 3 4
*/