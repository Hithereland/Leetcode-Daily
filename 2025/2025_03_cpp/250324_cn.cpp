// 2255. 统计是给定字符串前缀的字符串数目
// Easy
// https://leetcode.cn/problems/count-prefixes-of-a-given-string/

#include <string>
#include <unordered_set>
#include <vector>

class Solution
{
public:
    int countPrefixes(std::vector<std::string> &words, std::string s) {
        std::unordered_set<std::string> set;
        for (int i = 1; i <= s.size(); i++) {
            set.insert(s.substr(0, i));
        }

        int ret = 0;

        for (auto &w : words) {
            if (set.find(w) != set.end()) {
                ret += 1;
            }
        }

        return ret;
    }
};