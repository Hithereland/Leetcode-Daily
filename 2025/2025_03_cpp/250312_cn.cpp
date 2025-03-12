// 3305. 元音辅音字符串计数 I
// Medium
// https://leetcode.cn/problems/count-of-substrings-containing-every-vowel-and-k-consonants-i

#include <string>
#include <unordered_map>
#include <vector>

class Solution
{
public:
    bool check_vowel(int l, int r, std::unordered_map<char, std::vector<int>> &m, std::vector<int> consonants, int k) {
        bool ret = true;
        for (auto &p : m) {
            auto &v = p.second;
            int minus = l == 0 ? 0 : v[l - 1];
            if (v[r] - minus <= 0) ret = false;
        }

        int minus = l == 0 ? 0 : consonants[l - 1];
        if (consonants[r] - minus != k) {
            return false;
        }

        return ret;
    }

    int countOfSubstrings(std::string word, int k) {

        int ans = 0;

        std::unordered_map<char, std::vector<int>> prefix_cnt = {
            {'a', {0}},
            {'e', {0}},
            {'i', {0}},
            {'o', {0}},
            {'u', {0}}};

        std::vector<int> consonants_prefix_cnt = {0};

        for (int i = 0; i < word.size(); i++) {
            auto &x = word[i];
            if (prefix_cnt.find(x) != prefix_cnt.end()) {
                prefix_cnt[x][i] += 1;

            } else {
                consonants_prefix_cnt[i] += 1;
            }

            if (i < word.size() - 1) {
                for (auto &v : prefix_cnt) {
                    int last = v.second[i];
                    v.second.push_back(last);
                }
                // consonants_prefix_cnt
                int last = consonants_prefix_cnt[i];
                consonants_prefix_cnt.push_back(last);
            }
        }

        for (int left = 0; left < word.size(); left++)
            for (int right = left; right < word.size(); right++) {
                // with word[left] and with word[right]
                if (check_vowel(left, right, prefix_cnt, consonants_prefix_cnt, k)) {
                    ans += 1;
                }
            }

        return ans;
    }
};