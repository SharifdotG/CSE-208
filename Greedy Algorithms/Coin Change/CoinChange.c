#include <stdio.h>
#include <stdlib.h>

int coinChange(int coins[], int amount, int index) {
    if (amount == 0) return 0;

    if (coins[index] > amount) {
        return coinChange(coins, amount, index + 1);
    }

    return 1 + coinChange(coins, amount - coins[index], index);
}

int compare(const void *a, const void *b) {
    return *(int *)b - *(int *)a;
}

int main() {
    int coins[] = {1, 2, 5};
    int amount = 11;
    int n = sizeof(coins) / sizeof(coins[0]);

    qsort(coins, n, sizeof(int), compare);

    printf("Minimum number of coins required: %d\n", coinChange(coins, amount, 0));

    return 0;
}

/*
Input:
None

Output:
Minimum number of coins required: 3
*/