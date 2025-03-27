// 2780. Minimum Index of a Valid Split
// Medium
// https://leetcode.com/problems/minimum-index-of-a-valid-split/

#include <unordered_map>
#include <utility>
#include <vector>

class Solution
{

    typedef std::pair<int, int> p;

public:
    p findDom(std::vector<int> &nums) {
        std::unordered_map<int, int> m;
        for (auto &x : nums) {
            m[x] += 1;
        }
        int ret = 0, cnt = 0;
        for (auto &p : m) {
            if (p.second > cnt) {
                ret = p.first;
                cnt = p.second;
            }
        }
        return {ret, cnt};
    }

    int minimumIndex(std::vector<int> &nums) {
        int n = nums.size();
        p p = findDom(nums);
        int dom = p.first, dom_cnt = p.second;
        int left_cnt = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == dom) {
                left_cnt += 1;
            }

            if (2 * left_cnt > i + 1 && 2 * (dom_cnt - left_cnt) > n - i - 1) {
                return i;
            }
        }

        return -1;
    }
};