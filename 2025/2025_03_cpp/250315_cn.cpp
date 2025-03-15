// 3110. 字符串的分数
// Easy
// https://leetcode.cn/problems/score-of-a-string/

#include <string>

class Solution
{
public:
    int scoreOfString(std::string s) {
        int ans = 0;
        for (int i = 0; i < s.size() - 1; i++) {
            ans += abs(s[i] - s[i + 1]);
        }
        return ans;
    }
};