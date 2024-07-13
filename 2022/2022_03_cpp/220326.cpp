//
// Created by z on 3/26/2022.
// # 704

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1, ret = -1;
        while (l <= r)
        {
            int m = (l + r) / 2;
            if (target == nums[m])
                return m;
            else if (target > nums[m])
                l = m+1;
            else
                r = m-1;
        }
        return ret;
    }
};

