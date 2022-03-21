//
// Created by z on 3/21/2022.
// # 763
// 很简单的题，但是由于我的想法中有一个常数“26”避免不了，于是我参考了题解。其优雅程度实在震惊到了我。
class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> last_idx;

        for (int i = 0; i < s.size(); i++)
            last_idx[s[i]] = i;

        vector<int> ret;
        int prev = -1, flag = 0;

        for (int i = 0; i < s.size(); i++)
        {
            flag = last_idx[s[i]] > flag ? last_idx[s[i]] : flag;
            if (flag == i)
            {
                ret.push_back(flag - prev);
                prev = flag;
            }
        }

        return ret;
    }
};