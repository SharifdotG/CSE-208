#include <bits/stdc++.h>

using namespace std;

struct Edge {
    int source, destination, weight;
};

struct Graph {
    Edge *edge;
    int vertices, edges;
};

Graph *createGraph(int vertices, int edges) {
    Graph *graph = new Graph;

    graph->vertices = vertices;
    graph->edges = edges;
    graph->edge = new Edge[edges];

    return graph;
}

void printPath(vector<int> parent, int i) {
    if (i < 0) {
        return;
    }

    printPath(parent, parent[i]);
    cout << i << " ";
}

void printDistance(vector<int> distance, int vertices) {
    cout << "Vertex Distance from Source" << endl;
    
    for (int i = 0; i < vertices; i++) {
        cout << i << "\t\t" << distance[i] << endl;
    }
}

void BellmanFord(Graph *graph, int source) {
    int vertices = graph->vertices;
    int edges = graph->edges;

    vector<int> distance(vertices, INT_MAX);
    vector<int> parent(vertices, -1);

    distance[source] = 0;

    for (int i = 0; i < vertices - 1; i++) {
        for (int j = 0; j < edges; j++) {
            int u = graph->edge[j].source;
            int v = graph->edge[j].destination;
            int weight = graph->edge[j].weight;

            if (distance[u] != INT_MAX && distance[u] + weight < distance[v]) {
                distance[v] = distance[u] + weight;
                parent[v] = u;
            }
        }
    }

    for (int i = 0; i < edges; i++) {
        int u = graph->edge[i].source;
        int v = graph->edge[i].destination;
        int weight = graph->edge[i].weight;

        if (distance[u] != INT_MAX && distance[u] + weight < distance[v]) {
            cout << "Graph contains negative weight cycle" << endl;
            return;
        }
    }

    printDistance(distance, vertices);

    for (int i = 0; i < vertices; i++) {
        cout << "Path from vertex " << source << " to vertex " << i << " is: ";
        printPath(parent, i);
        cout << endl;
    }
}

int main() {
    Graph *graph = createGraph(5, 8);

    graph->edge[0].source = 0;
    graph->edge[0].destination = 1;
    graph->edge[0].weight = -1;

    graph->edge[1].source = 0;
    graph->edge[1].destination = 2;
    graph->edge[1].weight = 4;

    graph->edge[2].source = 1;
    graph->edge[2].destination = 2;
    graph->edge[2].weight = 3;

    graph->edge[3].source = 1;
    graph->edge[3].destination = 3;
    graph->edge[3].weight = 2;

    graph->edge[4].source = 1;
    graph->edge[4].destination = 4;
    graph->edge[4].weight = 2;

    graph->edge[5].source = 3;
    graph->edge[5].destination = 2;
    graph->edge[5].weight = 5;

    graph->edge[6].source = 3;
    graph->edge[6].destination = 1;
    graph->edge[6].weight = 1;

    graph->edge[7].source = 4;
    graph->edge[7].destination = 3;
    graph->edge[7].weight = -3;

    int source = 0;

    BellmanFord(graph, source);

    return 0;
}

/*
Input:
None

Output:
Vertex Distance from Source
0               0
1               -1
2               2
3               -2
4               1
Path from vertex 0 to vertex 0 is: 0 
Path from vertex 0 to vertex 1 is: 0 1 
Path from vertex 0 to vertex 2 is: 0 1 2 
Path from vertex 0 to vertex 3 is: 0 1 4 3 
Path from vertex 0 to vertex 4 is: 0 1 4 
*/