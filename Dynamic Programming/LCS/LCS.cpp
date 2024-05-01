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
    return dp[n][m];
}

int main() {
    string string1 = "AGGTAB";
    string string2 = "GXTXAYB";

    cout << lcs(string1, string2) << endl;

    return 0;
}

/*
Input:
None

Output:
Longest Common Subsequence: GTAB
Longest Common Subsequence Length: 4
*/