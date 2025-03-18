// 2401. Longest Nice Subarray
// Medium
// https://leetcode.com/problems/longest-nice-subarray/

#include <algorithm>
#include <vector>

class Solution
{
public:
    int longestNiceSubarray(std::vector<int> &nums) {
        int l = 0, r = 0, tmp = nums[0];
        int ans = 1;
        while (r < nums.size() - 1) {
            r++;
            while (l < r && (tmp & nums[r]) != 0) {
                tmp ^= nums[l];
                l++;
            }
            tmp |= nums[r];
            ans = std::max(ans, r - l + 1);
        }

        return ans;
    }
};