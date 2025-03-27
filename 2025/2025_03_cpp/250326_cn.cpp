// 2829. k-avoiding 数组的最小总和
// Medium
// https://leetcode.cn/problems/determine-the-minimum-sum-of-a-k-avoiding-array/

class Solution
{
public:
    int minimumSum(int n, int k) {
        int cnt = 0, sum = 0;
        for (int i = 1; i <= k / 2; i++) {
            cnt += 1;
            sum += i;
            if (cnt == n) {
                return sum;
            }
        }

        for (int i = k; i < 998244353; i++) {
            cnt += 1;
            sum += i;
            if (cnt == n) {
                return sum;
            }
        }

        return sum;
    }
};