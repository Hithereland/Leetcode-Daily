// 2529. Maximum Count of Positive Integer and Negative Integer
// Easy
// https://leetcode.com/problems/maximum-count-of-positive-integer-and-negative-integer/

#include <vector>

class Solution
{
public:
    int maximumCount(std::vector<int> &nums) {
        int n = 0, p = 0;
        for (auto &x : nums) {
            if (x > 0) {
                p += 1;
            } else if (x < 0) {
                n += 1;
            }
        }
        return std::max(n, p);
    }
};