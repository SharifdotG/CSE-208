#include <bits/stdc++.h>

using namespace std;

#define V 5

void dfs(int graph[V][V], bool visited[V], int start) {
    cout << start << " ";

    visited[start] = true;

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

    bool visited[V] = {false};

    dfs(graph, visited, 0);

    return 0;
}

/*
Input:
None

Output:
0 1 2 4 3
*/