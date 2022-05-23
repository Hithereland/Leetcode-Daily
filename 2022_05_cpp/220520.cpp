//
// Created by z on 2022/5/23.
// # 63

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {

        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        std::vector<std::vector<int>> ans(m, std::vector<int>(n, 0)), &g = obstacleGrid;
        ans[0][0] = 1;

        for (int r = 0; r < m; r++)
            for (int c = 0; c < n; c++) {

                if (g[r][c] == 1) {
                    ans[r][c] = 0;
                    continue;
                }

                if (r > 0) {
                    ans[r][c] += ans[r-1][c];
                }

                if (c > 0) {
                    ans[r][c] += ans[r][c-1];
                }
            }

        return ans[m-1][n-1];
    }
};
