// 2716. 最小化字符串长度
// Easy
// https://leetcode.cn/problems/minimize-string-length/

#include <string>
#include <unordered_set>

class Solution
{
public:
    int minimizedStringLength(std::string s) {
        std::unordered_set<char> set;
        for (auto &x : s) {
            set.insert(x);
        }
        return set.size();
    }
};