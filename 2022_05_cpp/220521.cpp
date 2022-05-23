//
// Created by z on 2022/5/23.
// # 322

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {

        int n = coins.size(), k = amount;
        std::sort(coins.begin(), coins.end());
        std::vector<int> ans(k+1, INT_MAX);
        ans[0] = 0;


        for (int i = 1; i <= k; i++) {

            int tmp_ans = INT_MAX;
            for (auto x: coins) {
                if (i - x >= 0) {
                    tmp_ans = ans[i-x] < tmp_ans ? ans[i-x] : tmp_ans;
                }
            }

            if (tmp_ans != INT_MAX) tmp_ans++;
            ans[i] = tmp_ans;
        }


        return ans[k] == INT_MAX ? -1 : ans[k];
    }
};
