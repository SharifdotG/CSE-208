#include <stdio.h>
#include <stdlib.h>

struct Item {
    int value, weight;
};

int compare(const void *a, const void *b) {
    double r1 = (double) ((struct Item *) b)->value / ((struct Item *) b)->weight;
    double r2 = (double) ((struct Item *) a)->value / ((struct Item *) a)->weight;
    return r1 > r2 ? 1 : 0;
}

double fractionalKnapsack(int W, struct Item array[], int n) {
    qsort(array, n, sizeof(array[0]), compare);

    int currentWeight = 0;
    double finalValue = 0.0;
    
    for (int i = 0; i < n; i++) {
        if (currentWeight + array[i].weight <= W) {
            currentWeight += array[i].weight;
            finalValue += array[i].value;
        } else {
            int remain = W - currentWeight;
            finalValue += array[i].value * ((double) remain / array[i].weight);
            break;
        }
    }

    return finalValue;
}

int main() {
    int W = 50;
    struct Item array[] = {{60, 10}, {100, 20}, {120, 30}};
    int n = sizeof(array) / sizeof(array[0]);

    printf("Maximum value we can obtain: %.2lf\n", fractionalKnapsack(W, array, n));

    return 0;
}

/*
Output:
Maximum value we can obtain: 240
*/