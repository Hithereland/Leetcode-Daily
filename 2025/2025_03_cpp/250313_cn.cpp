// 3306. 元音辅音字符串计数 II
// Medium
// https://leetcode.cn/problems/count-of-substrings-containing-every-vowel-and-k-consonants-ii/

#include <iostream>
#include <string>
#include <unordered_map>

class Solution
{
public:
    bool checkVowelCnt(std::unordered_map<char, int> &m) {
        for (auto &p : m) {
            if (p.second == 0) {
                return false;
            }
        }
        return true;
    }

    long long countOfSubstringsAboveK(std::string &word, int k) {
        int no_vowel_cnt = 0;
        std::unordered_map<char, int> vowel_cnt_map = {
            {'a', 0},
            {'e', 0},
            {'i', 0},
            {'o', 0},
            {'u', 0},
        };

        int l = 0, r = 0;
        long long ret = 0;

        // from l to r-1 (exclude word[r])
        while (l < word.size()) {
            while (!(checkVowelCnt(vowel_cnt_map) && no_vowel_cnt >= k) && r < word.size()) {
                // invalid, r += 1
                auto new_ch = word[r];
                if (vowel_cnt_map.find(new_ch) != vowel_cnt_map.end()) {
                    vowel_cnt_map[new_ch] += 1;
                } else {
                    no_vowel_cnt += 1;
                }
                r += 1;
            }

            // check again
            if (!(checkVowelCnt(vowel_cnt_map) && no_vowel_cnt >= k)) {
                return ret;
            }

            // valid
            ret += word.size() - r + 1;

            // l += 1
            auto old_ch = word[l];
            if (vowel_cnt_map.find(old_ch) != vowel_cnt_map.end()) {
                vowel_cnt_map[old_ch] -= 1;
            } else {
                no_vowel_cnt -= 1;
            }
            l += 1;
        }

        return ret;
    }

    long long countOfSubstrings(std::string word, int k) {
        return countOfSubstringsAboveK(word, k) - countOfSubstringsAboveK(word, k + 1);
    }
};

int main() {
    auto s = Solution();
    std::cout << s.countOfSubstrings("aeiou", 0);
}