// 1636. Sort Array by Increasing Frequency
// Easy
// https://leetcode.com/problems/sort-array-by-increasing-frequency/

#include <algorithm>
#include <utility>
#include <vector>
#include <unordered_map>

class Solution
{
  public:
    std::vector<int> frequencySort(std::vector<int> &nums)
    {
        std::unordered_map<int, int> m;
        for (auto &x : nums) {
            m[x] = m.find(x) == m.end() ? 1 : m[x] + 1;
        }

        std::vector<std::pair<int, int>> arr(m.begin(), m.end());
        sort(arr.begin(), arr.end(),
             [](std::pair<int, int> a, std::pair<int, int> b) -> bool {
                 return a.second == b.second ? a.first > b.first
                                             : a.second < b.second;
             });

        std::vector<int> ret;
        for (auto &p : arr) {
            for (int i = 0; i < p.second; i++) {
                ret.push_back(p.first);
            }
        }

        return ret;
    }
};