//
// Created by z on 3/29/2022.
// # 287
// Actually there are solutions with constant extra space, but I did not figure out.
// Sooner or later I will learn to use loop graph totally.

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int, int> m;
        for (auto &x: nums)
        {
            if (m.find(x) == m.end())
                m[x] = 1;
            else
                return x;
        }
        return -1;
    }
};

