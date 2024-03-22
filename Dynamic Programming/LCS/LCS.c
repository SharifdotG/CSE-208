#include <stdio.h>
#include <string.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int lcs(char *string1, char *string2) {
    int n = strlen(string1);
    int m = strlen(string2);

    int dp[n + 1][m + 1];

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (i == 0 || j == 0) {
                dp[i][j] = 0;
            } else if (string1[i - 1] == string2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    // Main code ends here after writing "return dp[n][m]; }"

    // This is just for printing the DP table
    printf("DP Table: \n");
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            printf("%d ", dp[i][j]);
        }
        printf("\n");
    }

    // This is for backtracking and printing the LCS
    int length = dp[n][m];
    char lcsString[length + 1];

    int i = n, j = m;
    lcsString[length] = '\0';

    while (i > 0 && j > 0) {
        if (string1[i - 1] == string2[j - 1]) {
            lcsString[length - 1] = string1[i - 1];
            i--, j--, length--;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }

    printf("Longest Common Subsequence: %s\n", lcsString);

    printf("Longest Common Subsequence Length: ");
    return dp[n][m];
}

int main() {
    char s1[] = "AGGTAB";
    char s2[] = "GXTXAYB";

    printf("%d\n", lcs(s1, s2));

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