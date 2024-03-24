#include <stdio.h>

#define V 5 // Change the value of V according to the number of vertices in the graph

void dfs(int graph[V][V], int visited[V], int start) {
    printf("%d ", start);

    visited[start] = 1;

    for (int i = 0; i < V; i++) {
        if (graph[start][i] == 1 && !visited[i]) {
            dfs(graph, visited, i);
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

    int visited[V] = {0};

    dfs(graph, visited, 0);

    return 0;
}

/*
Output:
0 1 2 4 3
*/