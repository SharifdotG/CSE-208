#include <bits/stdc++.h>

using namespace std;

int lcs(string string1, string string2) {
    int n = string1.size();
    int m = string2.size();

    int dp[n + 1][m + 1];

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (i == 0 || j == 0) {
                dp[i][j] = 0;
            } else if (string1[i - 1] == string2[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    // Main code ends here after writing "return dp[n][m]; }"!

    // This is just for printing the DP table
    cout << "DP Table: " << endl;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }

    // This is for backtracking and printing the LCS
    int length = dp[n][m];
    string lcsString;

    int i = n, j = m;
    while (i > 0 && j > 0) {
        if (string1[i - 1] == string2[j - 1]) {
            lcsString = string1[i - 1] + lcsString;
            i--, j--;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }

    cout << "Longest Common Subsequence: " << lcsString << endl;

    cout << "Longest Common Subsequence Length: ";
    return length;
}

int main() {
    string string1 = "AGGTAB";
    string string2 = "GXTXAYB";

    cout << lcs(string1, string2) << endl;

    return 0;
}

/* Output:
DP Table: 
0 0 0 0 0 0 0 0 
0 0 0 0 0 1 1 1 
0 1 1 1 1 1 1 1
0 1 1 1 1 1 1 1
0 1 1 2 2 2 2 2
0 1 1 2 2 3 3 3
0 1 1 2 2 3 3 4
Longest Common Subsequence: GTAB
Longest Common Subsequence Length: 4
*/