#include <bits/stdc++.h>

using namespace std;

int knapsack(int weights[], int values[], int n, int capacity) {
    int dp[n + 1][capacity + 1];
    
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= capacity; w++) {
            if (i == 0 || w == 0) {
                dp[i][w] = 0;
            } else if (weights[i - 1] <= w) {
                dp[i][w] = max(values[i - 1] + dp[i - 1][w - weights[i - 1]], dp[i - 1][w]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }
    // Main code ends here after writing "return dp[n][capacity]; }"

    // This is just for printing the DP table
    cout << "DP Table: " << endl;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= capacity; j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }

    cout << "Maximum value: ";
    return dp[n][capacity];
}

int main() {
    int weights[] = {2, 3, 4, 5};
    int values[] = {3, 4, 5, 6};
    int capacity = 5;
    int n = sizeof(values) / sizeof(values[0]);

    cout << knapsack(weights, values, n, capacity) << endl;

    return 0;
}

/* Output:
DP Table: 
0 0 0 0 0 0 
0 0 3 3 3 3
0 0 3 4 4 7
0 0 3 4 5 7
0 0 3 4 5 7
Maximum value: 7
*/