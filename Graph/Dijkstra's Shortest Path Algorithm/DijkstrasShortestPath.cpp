#include <bits/stdc++.h>

using namespace std;

#define V 9

int minDistance(int distances[], bool visited[]) {
    int minDistance = INT_MAX, minVertexIndex;

    for (int v = 0; v < V; v++) {
        if (!visited[v] && distances[v] <= minDistance) {
            minDistance = distances[v];
            minVertexIndex = v;
        }
    }

    return minVertexIndex;
}

void printSolution(int distances[]) {
    cout << "Vertex \t Distance from Source" << endl;
    for (int i = 0; i < V; i++) {
        cout << i << " \t\t " << distances[i] << endl;
    }
}

void dijkstra(int graph[V][V], int source) {
    int distances[V];
    bool visited[V];

    for (int i = 0; i < V; i++) {
        distances[i] = INT_MAX;
        visited[i] = false;
    }

    distances[source] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(distances, visited);

        visited[u] = true;

        for (int v = 0; v < V; v++) {
            if (!visited[v] && graph[u][v] && distances[u] != INT_MAX && distances[u] + graph[u][v] < distances[v]) {
                distances[v] = distances[u] + graph[u][v];
            }
        }
    }

    printSolution(distances);
}

int main() {
    int graph[V][V] = {
        {0, 4, 0, 0, 0, 0, 0, 8, 0},
        {4, 0, 8, 0, 0, 0, 0, 11, 0},
        {0, 8, 0, 7, 0, 4, 0, 0, 2},
        {0, 0, 7, 0, 9, 14, 0, 0, 0},
        {0, 0, 0, 9, 0, 10, 0, 0, 0},
        {0, 0, 4, 14, 10, 0, 2, 0, 0},
        {0, 0, 0, 0, 0, 2, 0, 1, 6},
        {8, 11, 0, 0, 0, 0, 1, 0, 7},
        {0, 0, 2, 0, 0, 0, 6, 7, 0}
    };

    dijkstra(graph, 0);

    return 0;
}

/*
Input:
None

Output:
Vertex   Distance from Source
0                0
1                4
2                12
3                19
4                21
5                11
6                9
7                8
8                14
*/