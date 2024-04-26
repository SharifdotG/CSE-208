#include <stdio.h>
#include <stdbool.h>

#define V 4

bool isSafe(int vertex, bool graph[V][V], int colors[], int color) {
    for (int i = 0; i < V; i++) {
        if (graph[vertex][i] && color == colors[i]) {
            return false;
        }
    }

    return true;
}

bool graphColoringUtil(bool graph[V][V], int n, int colors[], int vertex) {
    if (vertex == V) {
        return true;
    }

    for (int color = 1; color <= n; color++) {
        if (isSafe(vertex, graph, colors, color)) {
            colors[vertex] = color;

            if (graphColoringUtil(graph, n, colors, vertex + 1)) {
                return true;
            }

            colors[vertex] = 0;
        }
    }

    return false;
}

bool graphColoring(bool graph[V][V], int n) {
    int colors[V];

    for (int i = 0; i < V; i++) {
        colors[i] = 0;
    }

    if (!graphColoringUtil(graph, n, colors, 0)) {
        return false;
    }

    for (int i = 0; i < V; i++) {
        printf("%d ", colors[i]);
    }

    return true;
}

int main() {
    bool graph[V][V] = {
        {0, 1, 1, 1},
        {1, 0, 1, 0},
        {1, 1, 0, 1},
        {1, 0, 1, 0}
    };

    int n = 3;

    graphColoring(graph, n);

    return 0;
}

/*
Input:
None

Output:
1 2 3 2
*/