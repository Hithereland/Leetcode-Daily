// No. 1140
// https://leetcode.com/problems/stone-game-ii/

class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        // dp[i][j] means the maximun sum Alice can take after i when M = j
        int n = piles.size();
        vector<vector<int> > dp(n, vector<int>(101));
        vector<int> sufsum(n);
        
        sufsum[n-1] = piles[n-1];
        for (int i = n-2; i >= 0; i--)
            sufsum[i] = piles[i] + sufsum[i+1];
        
        for (int i = n-1; i >= 0; i--) {
            for (int j = 1; j <= 100; j++) {
                int m = j, maxans = 0;
                for (int k = 1; k <= 2*m; k++) {
                    int tmpans;
                    if (k+i >= n) {
                        tmpans = sufsum[i];
                    } else {
                        int nm = max(k, m);
                        tmpans = sufsum[i] - dp[k+i][nm];
                    }
                    maxans = max(maxans, tmpans);
                }
                dp[i][j] = maxans;
            }
        }
        
        return dp[0][1];
    }
};