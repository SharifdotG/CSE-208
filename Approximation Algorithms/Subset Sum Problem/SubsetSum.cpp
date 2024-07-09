#include <bits/stdc++.h>

using namespace std;

int subsetSum(int array[], int n, int sum) {
    bool dp[n + 1][sum + 1];

    for (int i = 0; i <= n; i++) {
        dp[i][0] = true;
    }

    for (int i = 1; i <= sum; i++) {
        dp[0][i] = false;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {
            if (array[i - 1] > j) {
                dp[i][j] = dp[i - 1][j];
            } else {
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - array[i - 1]];
            }
        }
    }

    return dp[n][sum];
}

int main() {
    int array[] = {3, 34, 4, 12, 5, 2};
    int n = sizeof(array) / sizeof(array[0]);
    int sum = 9;

    cout << "Is there a subset with the given sum? " << (subsetSum(array, n, sum) ? "Yes" : "No") << endl;

    return 0;
}

/*
Input:
None

Output:
Is there a subset with the given sum? Yes
*/