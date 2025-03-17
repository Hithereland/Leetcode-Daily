// 2206. Divide Array Into Equal Pairs
// Easy
// https://leetcode.com/problems/divide-array-into-equal-pairs/

#include <vector>

class Solution
{
public:
    bool divideArray(std::vector<int> &nums) {
        std::vector<int> cnt(501);
        for (auto &x : nums) {
            cnt[x] = !cnt[x];
        }
        int ans = 0;
        for (auto &x : cnt) {
            ans += x;
        }

        return ans == 0;
    }
};