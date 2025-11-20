#include <iostream>
#include <vector>
#include <algorithm>

// ILO A-B
int n;
int memo[1000]; // we will initialize the elements to -1 ( -1 means, not solved it yet )
int getMinSteps(int n) {
    if (n == 1) return 0; // base case
    if (memo[n] != -1) return memo[n]; // we have solved it already :)
    int r = 1 + getMinSteps(n - 1); // '-1' step . 'r' will contain the optimal answer finally
    if (n % 2 == 0) r = std::min(r, 1 + getMinSteps(n / 2)); // '/2' step
    if (n % 3 == 0) r = std::min(r, 1 + getMinSteps(n / 3)); // '/3' step
    memo[n] = r; // save the result. If you forget this step, then it's same as plain recursion.
    return r;
}

int getMinStepsBottomUp(int n) {
    int dp[n + 1], i;
    dp[1] = 0; // trivial case
    for (i = 2; i <= n; i++) {
        dp[i] = 1 + dp[i - 1];
        if (i % 2 == 0) dp[i] = std::min(dp[i], 1 + dp[i / 2]);
        if (i % 3 == 0) dp[i] = std::min(dp[i], 1 + dp[i / 3]);
    }
    return dp[n];
}

// SUPP
// Recursive function with memoization
int countPaths(int i, int j, int cost, const std::vector<std::vector<int>>& mat, std::vector<std::vector<std::vector<int>>>& dp) {
    int M = mat.size();
    int N = mat[0].size();

    // Out of bounds or cost too low
    if (i >= M || j >= N || cost < mat[i][j])
        return 0;

    // Destination reached
    if (i == M - 1 && j == N - 1)
        return (cost == mat[i][j]) ? 1 : 0;

    // Already computed
    if (dp[i][j][cost] != -1)
        return dp[i][j][cost];

    int remaining = cost - mat[i][j];

    // Move right and down
    int right = countPaths(i, j + 1, remaining, mat, dp);
    int down  = countPaths(i + 1, j, remaining, mat, dp);

    // Store result
    dp[i][j][cost] = right + down;
    return dp[i][j][cost];
}

int main() {
    std::cout << "Input n: ";
    std::cin >> n;
    std::fill(memo, memo + n + 1, -1);
    std::cout << "Minimum steps: " << getMinSteps( n) << std::endl;
    std::cout << "Minimum steps bottom up: " << getMinStepsBottomUp(n) << std::endl;


    std::vector<std::vector<int>> mat = {
        {4, 7, 1, 6},
        {6, 7, 3, 9},
        {3, 8, 1, 2},
        {7, 1, 7, 3}
    };

    int targetCost = 31;
    int M = mat.size();
    int N = mat[0].size();

    // 3D DP table: dp[i][j][cost]
    std::vector<std::vector<std::vector<int>>> dp(M, std::vector<std::vector<int>>(N, std::vector<int>(targetCost + 1, -1)));

    int totalPaths = countPaths(0, 0, targetCost, mat, dp);
    std::cout << "Number of paths with cost " << targetCost << ": " << totalPaths << std::endl;

    return 0;
}