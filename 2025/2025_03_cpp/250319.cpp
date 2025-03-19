// 3191. Minimum Operations to Make Binary Array Elements Equal to One I
// Medium
// https://leetcode.com/problems/minimum-operations-to-make-binary-array-elements-equal-to-one-i/

#include <vector>

class Solution
{
public:
    bool flipIdx(std::vector<int> &nums, int idx) {
        nums[idx] = !nums[idx];

        if (idx + 1 < nums.size())
            nums[idx + 1] = !nums[idx + 1];
        else
            return false;

        if (idx + 2 < nums.size())
            nums[idx + 2] = !nums[idx + 2];
        else
            return false;

        return true;
    }

    int minOperations(std::vector<int> &nums) {
        int idx = 0, ans = 0;

        while (idx + 2 < nums.size()) {

            if (nums[idx] == 1) {
                idx += 1;
                continue;
            }
            // nums[idx] == 0 now

            if (nums[idx + 1] == 1) {
                if (!flipIdx(nums, idx + 1)) {
                    return -1;
                }
                ans += 1;
            }

            if (nums[idx + 2] == 1) {
                if (!flipIdx(nums, idx + 2)) {
                    return -1;
                }
                ans += 1;
            }

            ans += 1;
            idx += 3;
        }

        if (idx != nums.size()) {
            for (int i = idx; i < nums.size(); i++) {
                if (nums[i] == 0) {
                    return -1;
                }
            }
        }

        return ans;
    }
};