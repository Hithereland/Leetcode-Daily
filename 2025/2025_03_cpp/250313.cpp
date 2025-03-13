// 3356. Zero Array Transformation II
// Medium
// https://leetcode.com/problems/zero-array-transformation-ii/

#include <vector>

class Solution
{
public:
    bool canBeZeroArray(std::vector<int> &nums, std::vector<std::vector<int>> &queries, int cnt) {
        std::vector<int> delta(nums.size() + 1);
        for (int i = 0; i < cnt; i++) {
            auto &q = queries[i];
            delta[q[0]] -= q[2];
            delta[q[1] + 1] += q[2];
        }

        int tmp_delta = 0;
        for (int i = 0; i < nums.size(); i++) {
            tmp_delta += delta[i];
            if (nums[i] + tmp_delta > 0) {
                return false;
            }
        }
        return true;
    }

    int minZeroArray(std::vector<int> &nums, std::vector<std::vector<int>> &queries) {
        int l = 0, r = queries.size();
        while (l < r) {
            int mid = (l + r) / 2;

            if (canBeZeroArray(nums, queries, mid)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }

        if (canBeZeroArray(nums, queries, l)) {
            return l;
        } else {
            return -1;
        }
    }
};