//
// Created by z on 2022/5/23.
// # 647

class Solution {
public:
    int countSubstrings(string s) {

        int n = s.size(), ans = 0;

        // odd
        for (int i = 0; i < n; i++) {

            int bias = 0;
            while (bias <= i && bias + i < n) {

                if (s[i-bias] != s[i+bias])
                    break;
                else {
                    bias++;
                    ans++;
                }
            }
        }

        // even
        for (int i = 0; i < n-1; i++) {

            if (s[i] != s[i+1])
                continue;

            int bias = 0;
            while (bias <= i && bias + i + 1 < n) {

                if (s[i-bias] != s[i+bias+1])
                    break;
                else {
                    bias++;
                    ans++;
                }
            }
        }


        return ans;
    }
};
