#include <stdio.h>
#include <stdlib.h>

int coinChange(int coins[], int amount, int index, int frequency[]) {
    if (amount == 0) return 0;

    if (coins[index] > amount) {
        return coinChange(coins, amount, index + 1, frequency);
    }

    frequency[index]++;
    return 1 + coinChange(coins, amount - coins[index], index, frequency);
}

int compare(const void *a, const void *b) {
    return *(int *)b - *(int *)a;
}

int main() {
    int coins[] = {1, 2, 5};
    int amount = 11;
    int n = sizeof(coins) / sizeof(coins[0]);

    int frequency[n];
    for (int i = 0; i < n; i++) {
        frequency[i] = 0;
    }

    qsort(coins, n, sizeof(int), compare);

    printf("Minimum number of coins required: %d\n", coinChange(coins, amount, 0, frequency));

    printf("Coins used:\n");
    for (int i = 0; i < n; i++) {
        printf("Coin %d used %d times\n", coins[i], frequency[i]);
    }

    return 0;
}

/*
Output:
Minimum number of coins required: 3
Coins used:
Coin 5 used 2 times
Coin 2 used 0 times
Coin 1 used 1 times
*/