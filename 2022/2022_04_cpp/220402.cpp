//
// Created by z on 4/3/2022.
// # 680

class Solution {
public:
    bool validPalindrome(string s, int mod=1) {
        for (int i = 0; i < s.size()/2; i++)
        {
            int j = s.size()-1-i;
            if (s[i] == s[j]) continue;
            if (mod == 1)
            {
                return validPalindrome(s.substr(i, j-i), 0) ||
                       validPalindrome(s.substr(i+1, j-i), 0);
            }
            return 0;
        }
        return 1;
    }
};

