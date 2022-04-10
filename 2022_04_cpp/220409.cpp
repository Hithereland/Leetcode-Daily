//
// Created by z on 4/10/2022.
// # 347

class Solution {
public:

    vector<int> topKFrequent(vector<int>& nums, int k) {
        typedef pair<int, int> p;
        vector<p> ww;
        vector<int> ret;
        unordered_map<int, int> m;
        for (auto x: nums)
            if (m.find(x) == m.end())
                m[x] = 1;
            else
                m[x]++;
        for (auto ppp: m)
            ww.push_back(ppp);
        sort(ww.begin(), ww.end(), [](p a, p b)->bool{ return a.second > b.second; });
        for (int i = 0; i < k; i++)
            ret.push_back(ww[i].first);
        return ret;
    }
};

