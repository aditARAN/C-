#include <iostream>
#include <vector>
#include <climits>

using namespace std;

// Function to find the minimum number of multiplications needed to multiply a chain of matrices
int matrixChainMultiplication(vector<int> dims) {
    int n = dims.size() - 1;
    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int len = 2; len <= n; len++) {
        for (int i = 0; i < n - len + 1; i++) {
            int j = i + len - 1;
            dp[i][j] = INT_MAX;
            for (int k = i; k < j; k++) {
                int cost = dp[i][k] + dp[k + 1][j] + dims[i] * dims[k + 1] * dims[j + 1];
                if (cost < dp[i][j]) {
                    dp[i][j] = cost;
                }
            }
        }
    }

    return dp[0][n - 1];
}

int main() {
    vector<int> matrixDimensions = {30, 35, 15, 5, 10, 20, 25};
    int minMultiplications = matrixChainMultiplication(matrixDimensions);
    cout << "Minimum number of multiplications: " << minMultiplications << endl;
    return 0;
}
