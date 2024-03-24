#include <stdio.h>
#include <stdlib.h>

struct Item {
    int value, weight;
};

int compare(const void *item1, const void *item2) {
    double ratio1 = (double) ((struct Item *) item2)->value / ((struct Item *) item2)->weight;
    double ratio2 = (double) ((struct Item *) item1)->value / ((struct Item *) item1)->weight;
    
    if (ratio1 > ratio2) return 1;
    else if (ratio1 < ratio2) return -1;
    else return 0;
}

double fractionalKnapsack(int capacity, struct Item items[], int n, int index) {
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
    struct Item items[] = {
        {60, 10},
        {100, 20},
        {120, 30}
    };
    
    int n = sizeof(items) / sizeof(items[0]);
    int capacity = 50;

    qsort(items, n, sizeof(struct Item), compare);

    printf("Maximum value we can obtain: %.2lf\n", fractionalKnapsack(capacity, items, n, 0));

    return 0;
}

/*
Output:
Maximum value we can obtain: 240.00
*/