#include <stdio.h>

struct Item {
    int value, weight;
};

double fractionalKnapsack(int W, struct Item arr[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if ((double) arr[j].value / arr[j].weight < (double) arr[j + 1].value / arr[j + 1].weight) {
                struct Item temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    int curWeight = 0;
    double finalValue = 0.0;
    
    for (int i = 0; i < n; i++) {
        if (curWeight + arr[i].weight <= W) {
            curWeight += arr[i].weight;
            finalValue += arr[i].value;
        } else {
            int remain = W - curWeight;
            finalValue += arr[i].value * ((double) remain / arr[i].weight);
            break;
        }
    }

    return finalValue;
}

int main() {
    int W = 50;
    struct Item arr[] = {{60, 10}, {100, 20}, {120, 30}};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Maximum value we can obtain: %.2lf\n", fractionalKnapsack(W, arr, n));

    return 0;
}