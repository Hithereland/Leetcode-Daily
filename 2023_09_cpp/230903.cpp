// 62
// https://leetcode.com/problems/unique-paths/submissions/

/*
 * very easy dp, o(n) space, not o(mn)
 */

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(2, vector<int>(n));
        for (int i = 0; i < n; i++) {
            dp[0][i] = 1;
        }
        for (int i = 1; i < m; i++) {
            int now = i % 2, prev = (i + 1) % 2;
            dp[now][0] = dp[prev][0];
            for (int j = 1; j < n; j++) {
                dp[now][j] = dp[prev][j] + dp[now][j-1];
            }
        }
        return dp[(m-1)%2][n-1];
    }
};