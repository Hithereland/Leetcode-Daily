//
// Created by z on 3/23/2022.
// # 991
// 代码看起来挺简单的(笑)，其实想了很久，TLE了不知道多少次，最终通过了，但是结果也没有特别理想。是这十多天来遇到的最难的题之一了吧。
class Solution {
public:
    int brokenCalc(int startValue, int target) {
        int s = startValue, t = target;
        if (t <= s)
            return s - t;

        double q = t * 1.0 / s;
        int x = 1;

        while (x < q)
            x *= 2;

        int ret = 0;
        while (x*(s-1) >= t)
        {
            s--;
            ret++;
        }

        return ret + 1 + brokenCalc(2*s, t);
    }
};
