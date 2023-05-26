// No. 837
// https://leetcode.com/problems/new-21-game/

class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        
        if (k == 0 || maxPts + k - 1 <= n) {
            return 1.0;
        }
        
        vector<double> dp(n + 1); // dp[i] means: the probability of keeping drawing until reach i, and the sum just equals to i
        double currSum = 1.0;
        double ans = 0.0;

        dp[0] = 1.0;

        for (int i = 1; i < n+1; i++) {

            dp[i] = currSum / maxPts;

            if (i < k) 
                currSum += dp[i];

             else 
                ans += dp[i];
            
            if (i - maxPts >= 0) 
                currSum -= dp[i - maxPts];
            
        }

        return ans;
    }
};