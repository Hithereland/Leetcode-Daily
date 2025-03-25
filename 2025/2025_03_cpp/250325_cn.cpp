// 2711. 对角线上不同值的数量差
// Medium
// https://leetcode.cn/problems/difference-of-number-of-distinct-values-on-diagonals/

// Not the best time

#include <cstdlib>
#include <unordered_set>
#include <vector>

class Solution
{
public:
    inline bool is_valid(const std::vector<std::vector<int>> &grid, int r, int c) {
        return r >= 0 && r < grid.size() && c >= 0 && c < grid[0].size();
    }

    int countTopLeft(const std::vector<std::vector<int>> &grid, int r, int c) {
        std::unordered_set<int> set;
        for (int i = 1; i < grid.size(); i++) {
            int tmp_r = r - i, tmp_c = c - i;
            if (is_valid(grid, tmp_r, tmp_c)) {
                set.insert(grid[tmp_r][tmp_c]);
            } else {
                break;
            }
        }
        return set.size();
    }

    int countBottomRight(const std::vector<std::vector<int>> &grid, int r, int c) {
        std::unordered_set<int> set;
        for (int i = 1; i < grid.size(); i++) {
            int tmp_r = r + i, tmp_c = c + i;
            if (is_valid(grid, tmp_r, tmp_c)) {
                set.insert(grid[tmp_r][tmp_c]);
            } else {
                break;
            }
        }
        return set.size();
    }

    std::vector<std::vector<int>> differenceOfDistinctValues(std::vector<std::vector<int>> &grid) {
        std::vector<std::vector<int>> ret(grid.size(), std::vector<int>(grid[0].size()));
        for (int r = 0; r < grid.size(); r++)
            for (int c = 0; c < grid[0].size(); c++) {
                ret[r][c] = std::abs(countTopLeft(grid, r, c) - countBottomRight(grid, r, c));
            }

        return ret;
    }
};
