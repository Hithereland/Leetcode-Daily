//
// Created by z on 2022/5/23.
// # 474

/*
 * dp[i][j][k] 给出前 i 个 str，0 个数不超过 j，1 个数不超过 k，此时的 ans
 * dp[i][j][k] 构造方式：要么选入第 i 个 str，要么不要
 */
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {

        std::vector<std::vector<std::vector<int>>> dp(strs.size()+1, std::vector<std::vector<int>>(m+1, std::vector<int>(n+1, 0)));

        for (int i = 0; i < strs.size(); i++) {

            int zeros = std::count(strs[i].begin(), strs[i].end(), '0');
            int ones = strs[i].size() - zeros;

            int idx = i+1;

            for (int j = 0; j <= m; j++)
                for (int k = 0; k <= n; k++) {

                    if (j - zeros < 0 || k - ones < 0) {
                        dp[idx][j][k] = dp[idx-1][j][k];
                    } else {
                        dp[idx][j][k] = max(dp[idx-1][j][k], 1+dp[idx-1][j-zeros][k-ones]);
                    }
                }
        }

        return dp[strs.size()][m][n];
    }
};
