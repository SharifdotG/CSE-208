#include <bits/stdc++.h>

using namespace std;

struct Item {
    int value, weight;
};

bool compare(Item a, Item b) {
    double ratio1 = (double) a.value / a.weight;
    double ratio2 = (double) b.value / b.weight;
    return ratio1 > ratio2;
}

double fractionalKnapsack(int capacity, Item items[], int n, int index) {
    if (index >= n || capacity <= 0) {
        return 0;
    }

    if (items[index].weight <= capacity) {
        return items[index].value + fractionalKnapsack(capacity - items[index].weight, items, n, index + 1);
    }

    double fraction = (double) capacity / items[index].weight;
    return items[index].value * fraction + fractionalKnapsack(0, items, n, index + 1);
}

int main() {
    int capacity = 50;
    Item items[] = {{60, 10}, {100, 20}, {120, 30}};
    int n = sizeof(items) / sizeof(items[0]);

    sort(items, items + n, compare);

    cout << "Maximum value we can obtain: " << fractionalKnapsack(capacity, items, n, 0) << endl;

    return 0;
}

/*
Output:
Maximum value we can obtain: 240
*/