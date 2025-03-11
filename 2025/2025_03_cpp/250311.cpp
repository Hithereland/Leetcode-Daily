// 1358. Number of Substrings Containing All Three Characters
// Medium
// https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/

#include <string>

inline int c2idx(char x) {
    return x - 'a';
}

class Solution
{
public:
    int numberOfSubstrings(std::string s) {
        int left = 0, right = 0, ans = 0;
        int numbering[3] = {0, 0, 0};

        while (left < s.size()) {
            bool valid = false;
            while (right < s.size()) {
                if (numbering[0] && numbering[1] && numbering[2]) {
                    valid = true;
                    break;
                }
                numbering[c2idx(s[right])] += 1;
                right += 1;
            }
            valid = numbering[0] && numbering[1] && numbering[2];

            if (valid) ans += s.size() - right + 1;
            numbering[c2idx(s[left])] -= 1;
            left += 1;
            if (right == s.size() && valid == false) {
                break;
            }
        }

        return ans;
    }
};