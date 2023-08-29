// No. 2483
// https://leetcode.com/problems/minimum-penalty-for-a-shop/

class Solution {
public:
    int bestClosingTime(string customers) {
        int ret = 0, min_penalty = 0, tmp_penalty = 0;
        for (int i = 0; i < customers.size(); i++) {
            auto &x = customers[i];
            if (x == 'Y') {
                tmp_penalty--;
            } else {
                tmp_penalty++;
            }

            if (tmp_penalty < min_penalty) {
                min_penalty = tmp_penalty;
                ret = i+1;
            }
        }
        return ret;
    }
};