// 3340. 检查平衡字符串
// Easy
// https://leetcode.cn/problems/check-balanced-string/

#include <string>

class Solution
{
public:
    bool isBalanced(std::string num) {
        int odd = 0, even = 0;
        for (int i = 0; i < num.size(); i++) {
            if (i % 2) {
                odd += num[i] - '0';
            } else {
                even += num[i] - '0';
            }
        }
        return odd == even;
    }
};