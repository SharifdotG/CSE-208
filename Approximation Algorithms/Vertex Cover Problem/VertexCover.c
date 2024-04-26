#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_VERTICES 100

struct Graph {
    int V;
    int **adjList;
};

struct Graph* createGraph(int V) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));

    graph->V = V;
    graph->adjList = (int**)malloc(V * sizeof(int*));

    for (int i = 0; i < V; i++) {
        graph->adjList[i] = (int*)malloc(V * sizeof(int));

        for (int j = 0; j < V; j++) {
            graph->adjList[i][j] = 0;
        }
    }

    return graph;
}

void addEdge(struct Graph* graph, int vertex1, int vertex2) {
    graph->adjList[vertex1][vertex2] = 1;
    graph->adjList[vertex2][vertex1] = 1;
}

void printVertexCover(struct Graph* graph) {
    bool visited[MAX_VERTICES] = {false};
    
    for (int u = 0; u < graph->V; u++) {
        if (!visited[u]) {
            for (int v = 0; v < graph->V; v++) {
                if (graph->adjList[u][v] && !visited[v]) {
                    visited[v] = true;
                    visited[u] = true;
                    
                    break;
                }
            }
        }
    }

    for (int i = 0; i < graph->V; i++) {
        if (visited[i]) {
            printf("%d ", i);
        }
    }
}

int main() {
    struct Graph* graph = createGraph(7);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 3, 4);
    addEdge(graph, 4, 5);
    addEdge(graph, 5, 6);

    printVertexCover(graph);

    return 0;
}

/*
Input:
None

Output:
0 1 3 4 5 6
*/