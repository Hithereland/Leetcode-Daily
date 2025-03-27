// 2712. 使所有字符相等的最小成本
// Medium
// https://leetcode.cn/problems/minimum-cost-to-make-all-characters-equal/

#include <algorithm>
#include <string>

class Solution
{
public:
    long long onesideCost(std::string s, char target) {
        int n = s.size();
        long long ret = 0;
        char prev = target;
        for (int i = 0; i < n; i++) {
            if (s[i] == prev) {
                continue;
            } else {
                ret += n - i;
                prev = s[i];
            }
        }

        return ret;
    }

    long long minimumCost(std::string s) {
        auto left = s.substr(0, s.size() / 2);
        auto right = s.substr(s.size() / 2);
        std::reverse(left.begin(), left.end());

        long long to1 = onesideCost(left, '1') + onesideCost(right, '1');
        long long to0 = onesideCost(left, '0') + onesideCost(right, '0');

        return std::min(to0, to1);
    }
};