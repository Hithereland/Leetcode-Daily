// 2707
// https://leetcode.com/problems/extra-characters-in-a-string/

/*
 * 数据量小，不用 trie 树，直接循环一把梭
 */

class Solution {
    
    const int MMAX = 114514;
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        int n = s.size();
        vector<int> dp(n+1, MMAX);
        unordered_map<string, int> m;
        for (auto x: dictionary) {
            m[x] = 1;    
        }
        
        dp[0] = 0; // when 0 is not included
        for (int i = 0; i <= n; i++) {
            if (i != 0) {
                dp[i] = min(dp[i-1]+1, dp[i]);
            }
            string tmp_str = "";
            for (int j = 0; i+j < n; j++) {
                tmp_str += s[i+j];
                if (m.find(tmp_str) != m.end()) {
                    dp[i+j+1] = min(dp[i], dp[i+j+1]);
                }
            }
        }
        return dp[n];
    }
};