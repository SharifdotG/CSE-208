#include <bits/stdc++.h>

using namespace std;

#define V 4

int travellingSalesmanProblem(int graph[][V], int start) {
    int vertex[V - 1];

    for (int i = 0, k = 0; i < V; i++) {
        if (i != start) {
            vertex[k++] = i;
        }
    }

    int minPath = INT_MAX;

    do {
        int currentPathWeight = 0, k = start;

        for (int i = 0; i < V - 1; i++) {
            currentPathWeight += graph[k][vertex[i]];
            k = vertex[i];
        }

        currentPathWeight += graph[k][start];
        minPath = min(minPath, currentPathWeight);
    } while (next_permutation(vertex, vertex + V - 1));

    return minPath;
}

int main() {
    int graph[][V] = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };

    int start = 0;

    cout << "The minimum path weight is " << travellingSalesmanProblem(graph, start) << endl;

    return 0;
}

/*
Input:
None

Output:
The minimum path weight is 80
*/