// 2191. Sort the Jumbled Numbers
// Medium
// https://leetcode.com/problems/sort-the-jumbled-numbers/

#include <algorithm>
#include <vector>

class Solution
{
  public:
    int doMapping(std::vector<int> &mapping, int num)
    {
        int tens = 1, ret = 0;
        if (num == 0) {
            return mapping[0];
        }
        while (num) {
            ret += tens * mapping[num % 10];
            tens *= 10;
            num /= 10;
        }
        return ret;
    }

    std::vector<int> sortJumbled(std::vector<int> &mapping,
                                 std::vector<int> &nums)
    {
        std::vector<std::pair<int, int>> pairs;
        for (auto &num : nums) {
            pairs.push_back({num, doMapping(mapping, num)});
        }
        stable_sort(pairs.begin(), pairs.end(),
             [](std::pair<int, int> a, std::pair<int, int> b) -> bool {
                 return a.second < b.second;
             });

        std::vector<int> ret;
        for (auto &p : pairs) {
            ret.push_back(p.first);
        }

        return ret;
    }
};