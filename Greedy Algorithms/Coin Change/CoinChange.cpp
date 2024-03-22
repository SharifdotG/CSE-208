#include <bits/stdc++.h>

using namespace std;

int coinChange(int coins[], int amount, int index, int frequency[]) {
    if (amount == 0) return 0;

    if (coins[index] > amount) {
        return coinChange(coins, amount, index + 1, frequency);
    }

    frequency[index]++;
    return 1 + coinChange(coins, amount - coins[index], index, frequency);
}

int main() {
    int coins[] = {1, 2, 5};
    int amount = 11;
    int n = sizeof(coins) / sizeof(coins[0]);

    int frequency[n] = {0};

    sort(coins, coins + n, greater<int>());
    
    cout << "Minimum number of coins required: " << coinChange(coins, amount, 0, frequency) << endl;

    cout << "Coins used:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Coin " << coins[i] << " used " << frequency[i] << " times" << endl;
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