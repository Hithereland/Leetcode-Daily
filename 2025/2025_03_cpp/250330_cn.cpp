// 2109. 向字符串添加kongge
// Medium
// https://leetcode.cn/problems/adding-spaces-to-a-string/

// 7m22s

#include <string>
#include <vector>

class Solution
{
public:
    std::string addSpaces(std::string s, std::vector<int> &spaces) {
        std::string ret;
        auto iter = spaces.begin();
        for (int i = 0; i < s.size(); i++) {
            if (iter != spaces.end() && i == *iter) {
                ret.append(1, ' ');
                iter++;
            }
            ret.append(1, s[i]);
        }

        return s;
    }
};
