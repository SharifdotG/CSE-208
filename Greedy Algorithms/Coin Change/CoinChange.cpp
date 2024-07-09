#include <bits/stdc++.h>

using namespace std;

int coinChange(int coins[], int amount, int index) {
    if (amount == 0) return 0;

    if (coins[index] > amount) {
        return coinChange(coins, amount, index + 1);
    }

    return 1 + coinChange(coins, amount - coins[index], index);
}

int main() {
    int coins[] = {1, 2, 5};
    int amount = 11;
    int n = sizeof(coins) / sizeof(coins[0]);

    sort(coins, coins + n, greater<int>());
    
    cout << "Minimum number of coins required: " << coinChange(coins, amount, 0) << endl;

    return 0;
}

/*
Input:
None

Output:
Minimum number of coins required: 3
*/