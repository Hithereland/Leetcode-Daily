// 2033. Minimum Operations to Make a Uni-Value Grid
// Medium
// https://leetcode.com/problems/minimum-operations-to-make-a-uni-value-grid/

#include <algorithm>
#include <cstdlib>
#include <vector>

class Solution
{
public:
    int minOperations(std::vector<std::vector<int>> &grid, int x) {
        int mod_res = grid[0][0] % x, idx = 0;
        std::vector<int> div_res(grid.size() * grid[0].size());

        for (auto &r : grid)
            for (auto &val : r) {
                if (val % x != mod_res) {
                    return -1;
                }
                div_res[idx] = val / x;
                idx++;
            }

        std::sort(div_res.begin(), div_res.end());
        int target = div_res[div_res.size() / 2];

        int ans = 0;
        for (auto &val : div_res) {
            ans += std::abs(val - target);
        }

        return ans;
    }
};