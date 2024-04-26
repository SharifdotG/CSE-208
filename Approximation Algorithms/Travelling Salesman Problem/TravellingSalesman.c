#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define V 4

int min(int x, int y) {
    return (x < y) ? x : y;
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void reverse(int array[], int i, int j) {
    while (i < j) {
        swap(&array[i++], &array[j--]);
    }
}

bool nextPermutation(int array[], int n) {
    int i = n - 2;
    while (i >= 0 && array[i] >= array[i + 1]) {
        i--;
    }

    if (i < 0) {
        return false;
    }

    int j = n - 1;
    while (array[j] <= array[i]) {
        j--;
    }

    swap(&array[i], &array[j]);
    reverse(array, i + 1, n - 1);

    return true;
}

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
    } while (nextPermutation(vertex, V - 1));

    return minPath;
}

int main() {
    int graph[V][V] = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };

    int start = 0;

    printf("The minimum path weight is %d\n", travellingSalesmanProblem(graph, start));

    return 0;
}

/*
Input:
None

Output:
The minimum path weight is 80
*/