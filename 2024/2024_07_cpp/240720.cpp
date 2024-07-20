// 1605. Find Valid Matrix Given Row and Column Sums
// Medium
// https://leetcode.com/problems/find-valid-matrix-given-row-and-column-sums/

#include <algorithm>
#include <vector>

class Solution
{
public:
    std::vector<std::vector<int>> restoreMatrix(std::vector<int>& rowSum,
                                                std::vector<int>& colSum)
    {
        std::vector<std::vector<int>> ret(rowSum.size(),
                                          std::vector<int>(colSum.size(), 0));

        for (int r = 0; r < ret.size(); r++) {
            for (int c = 0; c < ret[0].size(); c++) {
                ret[r][c] = std::min(rowSum[r], colSum[c]);
                rowSum[r] -= ret[r][c];
                colSum[c] -= ret[r][c];
            }
        }

        return ret;
    }
};