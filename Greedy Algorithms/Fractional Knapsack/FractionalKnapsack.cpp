#include <bits/stdc++.h>

using namespace std;

struct Item {
    int value, weight;
};

bool compare(Item item1, Item item2) {
    double ratio1 = (double) item1.value / item1.weight;
    double ratio2 = (double) item2.value / item2.weight;
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
    Item items[] = {
        {60, 10},
        {100, 20},
        {120, 30}
    };
    
    int n = sizeof(items) / sizeof(items[0]);
    int capacity = 50;

    sort(items, items + n, compare);

    cout << "Maximum value we can obtain: " << fractionalKnapsack(capacity, items, n, 0) << endl;

    return 0;
}

/*
Output:
Maximum value we can obtain: 240
*/