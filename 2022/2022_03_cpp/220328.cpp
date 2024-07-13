//
// Created by z on 3/28/2022.
// # 81
// The normal solution is to use binary search, but I have no time today.
// One who cannot control himself will have a wholly bad day.

class Solution {
public:
    bool search(vector<int>& nums, int target) {

        for (auto &x: nums)
            if (target == x)
                return 1;

        return 0;
    }
};

