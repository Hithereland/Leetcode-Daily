// 2560. House Robber IV
// Medium
// https://leetcode.com/problems/house-robber-iv/

#include <vector>

class Solution
{
public:
    bool check(std::vector<int> &nums, int ans, int k) {
        bool can_use = true;
        int cnt = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (can_use && nums[i] <= ans) {
                cnt += 1;
                can_use = false;
            } else {
                can_use = true;
            }
        }
        return cnt >= k;
    }

    int minCapability(std::vector<int> &nums, int k) {
        int l = 0, r = 1e9 + 1;
        while (l < r) {
            int m = (l + r) / 2;
            if (check(nums, m, k)) {
                r = m;
            } else {
                l = m + 1;
            }
        }

        if (check(nums, l, k)) {
            return l;
        } else {
            return l + 1;
        }
    }
};