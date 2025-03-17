// 1963. 使字符串平衡的最小交换次数
// Medium
// https://leetcode.cn/problems/minimum-number-of-swaps-to-make-the-string-balanced/

#include <string>
class Solution
{
public:
    int minSwaps(std::string s) {
        int left_cnt = 0, changes = 0;
        for (auto &ch : s) {
            switch (ch) {
            case '[':
                left_cnt += 1;
                break;
            case ']':
                if (left_cnt != 0) {
                    left_cnt -= 1;
                } else {
                    changes += 1;
                    left_cnt += 1;
                }
                break;
            }
        }
        return changes;
    }
};