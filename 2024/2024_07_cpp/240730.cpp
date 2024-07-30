// 1653. Minimum Deletions to Make String Balanced
// Medium
// https://leetcode.com/problems/minimum-deletions-to-make-string-balanced/

#include <string>

class Solution
{
  public:
    int minimumDeletions(std::string s)
    {
        int left_as = 0, left_bs = 0, prev_ans = 0, ans = 0,
            min_after_b = false;
        for (int i = 0; i < s.size(); i++) {
            int ans_sub = prev_ans;
            if (s[i] == 'a') {
                if (min_after_b) {
                    // delete this 'a'
                    ans_sub++;
                }
                int ans_del_all_b = left_bs;
                ans               = std::min(ans_sub, ans_del_all_b);
                if (ans_del_all_b < ans_sub) {
                    ans         = ans_del_all_b;
                    min_after_b = false;
                } else {
                    // min_after_b remain the same
                    ans = ans_sub;
                }
                left_as++;
                prev_ans = ans;
            } else {
                ans         = prev_ans;
                min_after_b = true;
                left_bs++;
                prev_ans = ans;
            }
        }
        return ans;
    }
};

int main()
{
    Solution s;
    std::string str = "bbaaaaabb";
    s.minimumDeletions(str);
}