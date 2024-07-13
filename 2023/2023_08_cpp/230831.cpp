// 1326
// https://leetcode.com/problems/minimum-number-of-taps-to-open-to-water-a-garden/

/*
 * Actually not that hard, simple dp
 */

class Solution {

    const int MMAX = 114514;
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<int> arr(n+1, -1);
        vector<int> dp(n+1, MMAX);

        for (int i = 0; i <= n; i++) {
            int l = i - ranges[i], r = i + ranges[i];
            if (ranges[i] == 0) {
                continue;
            }
            if (l < 0) {
                l = 0;
            }
            if (r > n) {
                r = n;
            }
            arr[l] = max(arr[l], r);
        }

        dp[0] = 0;
        for (int i = 0; i <= n; i++) {
            if (arr[i] != -1) {
                int idx = arr[i];
                for (int j = i+1; j <= idx; j++) {
                    dp[j] = min(dp[j], dp[i] + 1);
                }
            }
        }

        if (dp[n] >= MMAX) {
            return -1;
        }
        return dp[n];
    }
};
