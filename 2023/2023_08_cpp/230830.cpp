// 2366
// https://leetcode.com/problems/minimum-replacements-to-sort-the-array/

/* 两个稍微难想到的地方：
 * 1）为什么 remainder / q + !!(remainder % q) + m > to_smaller 时候，这个 m 就是可行的
 * 2）为什么大的数最后会被分成 nums[i] / tmp_max + !!(nums[i] % tmp_max) 那么多份
 */

class Solution {
public:

    static int findTargetNum(int from, int to_smaller) {
        int l = 1, r = to_smaller;
        if (from % to_smaller == 0) {
            return to_smaller;
        }
        while (l < r-1) {
            int m = (l + r) / 2;
            int remainder = from % m;
            int q = from / m;
            if (remainder / q + !!(remainder % q) + m > to_smaller) {
                r = m;
            } else {
                l = m;
            }
        }
        return l;
    }

    long long minimumReplacement(vector<int>& nums) {
        long long ret = 0;
        int i = nums.size() - 1;
        int tmp_max = nums[i];

        for (; i >= 0; i--) {
            if (nums[i] > tmp_max) {
                int m = findTargetNum(nums[i], tmp_max);
                ret += (nums[i] / tmp_max + !!(nums[i] % tmp_max)) - 1;
                tmp_max = m;
            } else {
                tmp_max = nums[i];
            }
        }

        return ret;
    }
};

/*
 * 一开始思路错了，误打误撞得知如下题目的做法：
 *      给定正整数 x 和 y，怎么找最大的 z 使得 z 小于 x 并且 y % z = 0
 * 使用“整除分块”的每块的右结点，可以找出大于 x 的最小的 y % z' = 0 的 z'，而 x / z' 就得到 z
 */