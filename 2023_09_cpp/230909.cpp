// 377
// https://leetcode.com/problems/combination-sum-iv/submissions/

/*
 * simple dp， disgusting data
 */

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<long long> ans(target+1);
        ans[0] = 1;
        for (int i = 1; i <= target; i++) {
            for (auto &x: nums) {
                if (i - x < 0) {
                    continue;
                }
                ans[i] += ans[i-x];
                if (ans[i] >= INT_MAX) {
                    break;
                }
            }
        }
        return (int)ans[target];
    }
};