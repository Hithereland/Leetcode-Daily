//
// Created by z on 5/8/2022.
// # 581

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {

        std::vector<int> modl = nums;
        std::sort(modl.begin(), modl.end());

        int ret = 0;
        for (int i = 0; i < modl.size(); i++) {

            if (modl[i] == nums[i])
                ret++;
            else
                break;
        }

        if (ret == nums.size())
            return 0;

        for (int i = modl.size()-1; i >= 0; i--) {

            if (modl[i] == nums[i])
                ret++;
            else
                break;
        }

        return nums.size() - ret;
    }
};

