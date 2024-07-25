// 912. Sort an Array
// Medium
// https://leetcode.com/problems/sort-an-array/

#include <algorithm>
#include <vector>

class Solution
{
  public:
    std::vector<int> sortArray(std::vector<int> &nums)
    {
        // I am tired.
        sort(nums.begin(), nums.end());
        return nums;
    }
};