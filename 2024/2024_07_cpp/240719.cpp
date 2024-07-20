// 1380. Lucky Numbers in a Matrix
// Easy
// https://leetcode.com/problems/lucky-numbers-in-a-matrix/

#include <vector>

class Solution
{
public:
    std::vector<int> luckyNumbers(std::vector<std::vector<int>>& matrix)
    {
        for (int r = 0; r < matrix.size(); r++) {
            // Find min in the chosen row
            // Only one _min_idx because: all elements in the matrix are
            // distinct
            int _min = 100005, _min_idx = -1;
            for (int c = 0; c < matrix[r].size(); c++) {
                if (_min > matrix[r][c]) {
                    _min = matrix[r][c];
                    _min_idx = c;
                }
            }

            // Check if it is valid
            bool valid = true;
            for (int i = 0; i < matrix.size(); i++) {
                if (_min < matrix[i][_min_idx]) {
                    valid = false;
                    break;
                }
            }
            if (valid) return {_min};
        }

        return {};
    }
};