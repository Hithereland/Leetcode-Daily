// 2680. 最大或值
// Medium
// https://leetcode.cn/problems/maximum-or/

#include <algorithm>
#include <vector>

class Solution
{
public:
    long long maximumOr(std::vector<int> &nums, int k) {
        // 1100, 1001 -> 11000, 1001 -> 11001
        // 1001, 1100 -> 10010, 1100 -> 11010
        int n = nums.size();
        std::vector<int> prefix_or(n + 1), suffix_or(n + 1);

        // For i in nums:
        // prefix_or[i] == k means OR[nums[0] to nums[i-1]]
        // suffix_or[i] == l means OR[nums[i+1] to nums[n-1]]
        for (int i = 0; i < n; i++) {
            prefix_or[i + 1] = prefix_or[i] | nums[i];
            suffix_or[n - i - 1] = suffix_or[n - i] | (i > 0 ? nums[n - i] : 0);
        }

        long long ret = 0;
        for (int i = 0; i < n; i++) {
            long long x = nums[i];
            long long tmp_ans = (x << k) | prefix_or[i] | suffix_or[i];
            ret = std::max(ret, tmp_ans);
        }

        return ret;
    }
};