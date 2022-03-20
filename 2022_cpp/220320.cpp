//
// Created by z on 3/20/2022.
// #1007

class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        // init
        unordered_map<int, int> cnt, match_cnt;
        for (int i = -6; i < 7; i++)
        {
            cnt[i] = 0;
            match_cnt[i] = tops.size();
        }

        // count
        for (auto x : tops)
            cnt[x]++;
        for (auto x : bottoms)
            cnt[-x]++;

        // remove duplicates
        for (int i = 0; i < tops.size(); i++)
        {
            if (tops[i] == bottoms[i]) {
                int num = tops[i];
                cnt[num]--;
                cnt[-num]--;
                match_cnt[num]--;
            }
        }

        // ret
        int ret = 114514;
        for (int i = 1; i < 7; i++)
        {
            if (cnt[i] + cnt[-i] < match_cnt[i])
                continue;
            ret = min(ret, min(cnt[i], cnt[-i]));
        }

        if (ret == 114514)
            return -1;
        else
            return ret;
    }
};
