#include <iostream>
#include <vector>

using namespace std;

string longestCommonSubsequence(const string &str1, const string &str2) {
    int m = str1.length();
    int n = str2.length();

    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    // Build the dynamic programming table
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (str1[i - 1] == str2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    // Reconstruct the longest common subsequence
    int length = dp[m][n];
    string lcs(length, ' ');
    int i = m, j = n;

    while (i > 0 && j > 0) {
        if (str1[i - 1] == str2[j - 1]) {
            lcs[--length] = str1[i - 1];
            i--;
            j--;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }

    return lcs;
}

int main() {
    string str1 = "AGGTAB";
    string str2 = "GXTXAYB";

    string lcs = longestCommonSubsequence(str1, str2);

    cout << "Longest Common Subsequence: " << lcs << endl;

    return 0;
}
