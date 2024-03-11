#include <stdio.h>

struct Item {
    int value, weight;
};

double fractionalKnapsack(int W, struct Item array[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if ((double) array[j].value / array[j].weight < (double) array[j + 1].value / array[j + 1].weight) {
                struct Item temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }

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