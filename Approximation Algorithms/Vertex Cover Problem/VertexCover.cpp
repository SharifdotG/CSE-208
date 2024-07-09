#include <bits/stdc++.h>

using namespace std;

class Graph {
    int V;
    list<int> *adjList;

public:
    Graph(int V);
    void addEdge(int vertex1, int vertex2);
    void printVertexCover();
};

Graph::Graph(int V) {
    this->V = V;
    adjList = new list<int>[V];
}

void Graph::addEdge(int vertex1, int vertex2) {
    adjList[vertex1].push_back(vertex2);
    adjList[vertex2].push_back(vertex1);
}

void Graph::printVertexCover() {
    bool visited[V];
    for (int i = 0; i < V; i++) {
        visited[i] = false;
    }

    list<int>::iterator it;
    for (int u = 0; u < V; u++) {
        if (!visited[u]) {
            for (it = adjList[u].begin(); it != adjList[u].end(); it++) {
                int v = *it;
                
                if (!visited[v]) {
                    visited[v] = true;
                    visited[u] = true;
                    
                    break;
                }
            }
        }
    }

    for (int i = 0; i < V; i++) {
        if (visited[i]) {
            cout << i << " ";
        }
    }
}

int main() {
    Graph graph(7);
    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 3);
    graph.addEdge(3, 4);
    graph.addEdge(4, 5);
    graph.addEdge(5, 6);

    graph.printVertexCover();

    return 0;
}

/*
Input:
None

Output:
0 1 3 4 5 6
*/