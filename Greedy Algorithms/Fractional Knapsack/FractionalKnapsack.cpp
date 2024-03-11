#include <bits/stdc++.h>

using namespace std;

struct Item {
    int value, weight;
};

bool compare(Item a, Item b) {
    double r1 = (double) a.value / a.weight;
    double r2 = (double) b.value / b.weight;
    return r1 > r2;
}

double fractionalKnapsack(int W, Item array[], int n) {
    sort(array, array + n, compare);

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
    Item array[] = {{60, 10}, {100, 20}, {120, 30}};
    int n = sizeof(array) / sizeof(array[0]);

    cout << "Maximum value we can obtain: " << fractionalKnapsack(W, array, n) << endl;

    return 0;
}

/*
Output:
Maximum value we can obtain: 240
*/