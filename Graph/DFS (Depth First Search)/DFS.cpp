#include <bits/stdc++.h>

using namespace std;

void dfs(int graph[5][5], int start, bool visited[5]) {
    cout << start << " ";
    visited[start] = true;

    for (int i = 0; i < 5; i++) {
        if (graph[start][i] == 1 && !visited[i]) {
            dfs(graph, i, visited);
        }
    }
}

int main() {
    int graph[5][5] = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 1, 0},
        {1, 1, 0, 0, 1},
        {0, 1, 0, 0, 1},
        {0, 0, 1, 1, 0}
    };

    bool visited[5] = {false};

    dfs(graph, 0, visited);

    return 0;
}

/*
Output:
0 1 2 4 3
*/