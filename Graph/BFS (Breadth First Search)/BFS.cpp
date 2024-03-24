#include <bits/stdc++.h>

using namespace std;

void bfs(int graph[5][5], int start) {
    queue<int> q;
    bool visited[5] = {false};

    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        cout << node << " ";

        for (int i = 0; i < 5; i++) {
            if (graph[node][i] == 1 && !visited[i]) {
                q.push(i);
                visited[i] = true;
            }
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

    bfs(graph, 0);

    return 0;
}

/*
Output:
0 1 2 3 4
*/