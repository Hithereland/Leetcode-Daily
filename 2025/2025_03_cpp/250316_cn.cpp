// 2272. 最大波动的子字符串
// Hard
// https://leetcode.cn/problems/substring-with-largest-variance/

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

class Solution
{
public:
    int calcVariance(std::string &s, char x, char y) {
        std::vector<int> cnt_x(s.size() + 1), cnt_y(s.size() + 1);
        int min_x2y = s.size(), max_x2y = -s.size();
        int min_idx = 0, max_idx = 0;

        int ans = 0;

        for (int i = 0; i < s.size(); i++) {
            cnt_x[i + 1] = cnt_x[i];
            cnt_y[i + 1] = cnt_y[i];

            if (s[i] == x) {
                cnt_x[i + 1] += 1;
            } else if (s[i] == y) {
                cnt_y[i + 1] += 1;
            }

            // check ans
            int &tmp_cnt_x = cnt_x[i + 1], &tmp_cnt_y = cnt_y[i + 1];
            int &max_cnt_x = cnt_x[max_idx], &max_cnt_y = cnt_y[max_idx];
            int &min_cnt_x = cnt_x[min_idx], &min_cnt_y = cnt_y[min_idx];

            int ans_tomax = abs((tmp_cnt_x - tmp_cnt_y) - (max_cnt_x - max_cnt_y));
            int ans_tomin = abs((tmp_cnt_x - tmp_cnt_y) - (min_cnt_x - min_cnt_y));
            if (tmp_cnt_x == max_cnt_x || tmp_cnt_y == max_cnt_y) {
                if (tmp_cnt_x != 0 && tmp_cnt_y != 0) ans_tomax -= 1;
                else
                    ans_tomax = 0;
            }
            if (tmp_cnt_x == min_cnt_x || tmp_cnt_y == min_cnt_y) {
                if (tmp_cnt_x != 0 && tmp_cnt_y != 0) ans_tomin -= 1;
                else
                    ans_tomin = 0;
            }

            int tmp_ans = std::max(ans_tomax, ans_tomin);
            ans = std::max(ans, tmp_ans);

            if (tmp_cnt_x - tmp_cnt_y > max_cnt_x - max_cnt_y) {
                max_idx = i + 1;
            }
            if (tmp_cnt_x - tmp_cnt_y < min_cnt_x - min_cnt_y) {
                min_idx = i + 1;
            }
        }
        return ans;
    }

    int largestVariance(std::string s) {
        char alphabet[26];
        for (int i = 0; i < 26; i++) {
            alphabet[i] = i + 'a';
        }

        int ans = 0;
        for (int i = 0; i < 26; i++)
            for (int j = i + 1; j < 26; j++) {
                char x = alphabet[i], y = alphabet[j];
                ans = std::max(ans, calcVariance(s, x, y));
                std::cout << "x=" << x << ", y=" << y << ", ans=" << calcVariance(s, x, y) << std::endl;
            }

        return ans;
    }
};

int main() {
    auto so = Solution();
    so.largestVariance("baaa");
}