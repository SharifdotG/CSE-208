#include <bits/stdc++.h>

using namespace std;

#define V 5

void bfs(int graph[V][V], int start) {
    queue<int> q;
    bool visited[V] = {false};

    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        cout << node << " ";

        for (int i = 0; i < V; i++) {
            if (graph[node][i] == 1 && !visited[i]) {
                q.push(i);
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
Input:
None

Output:
0 1 2 3 4
*/