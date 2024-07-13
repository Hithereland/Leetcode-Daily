// No. 1406
// https://leetcode.com/problems/stone-game-iii/submissions/

class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int> dp(n), sufsum(n);
        
        sufsum[n-1] = stoneValue[n-1];
        for (int i = n-2; i >= 0; i--) {
            sufsum[i] = stoneValue[i] + sufsum[i+1];    
        }
        
        dp[n-1] = sufsum[n-1];
        for (int i = n-2; i >= 0; i--) {
            
            dp[i] = sufsum[i] - dp[i+1];
            
            if (i+2 < n) {
                dp[i] = max(dp[i], sufsum[i] - dp[i+2]);
            } else {
                dp[i] = max(dp[i], sufsum[i]);
            }
            
            if (i+3 < n) {
                dp[i] = max(dp[i], sufsum[i] - dp[i+3]);
            } else {
                dp[i] = max(dp[i], sufsum[i]);
            }
        }
        
        int Alice = dp[0], Bob = sufsum[0] - dp[0];
        
        if (Alice > Bob) {
            return "Alice";
        } else if (Alice < Bob) {
            return "Bob";
        } else {
            return "Tie";
        }
    }
};