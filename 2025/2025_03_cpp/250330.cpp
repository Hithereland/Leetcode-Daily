// 763. Partition Labels
// Medium
// https://leetcode.com/problems/partition-labels/

// 13m01s

#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>

typedef std::pair<int, int> p;

class Solution
{
public:
    std::vector<int> partitionLabels(std::string s) {
        std::unordered_map<char, p> m;
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            if (m.find(c) == m.end()) {
                m[c] = {i, i};
            } else {
                m[c].second = i;
            }
        }
        std::vector<p> pairs;

        for (auto &p : m) {
            pairs.push_back(p.second);
        }

        std::sort(pairs.begin(), pairs.end(), [](p a, p b) -> bool {
            return a.first < b.first;
        });

        std::vector<p> split_q;
        for (auto &p : pairs) {
            if (split_q.empty()) {
                split_q.push_back(p);
                continue;
            }
            // else
            auto &back = split_q.back();
            if (back.second > p.first) {
                back.second = std::max(back.second, p.second);
            } else {
                split_q.push_back(p);
            }
        }

        std::vector<int> ret;
        for (auto &p : split_q) {
            ret.push_back(p.second - p.first + 1);
        }

        return ret;
    }
};