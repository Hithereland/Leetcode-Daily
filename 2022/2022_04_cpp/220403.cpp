//
// Created by z on 4/3/2022.
// # 31

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if (nums.size() == 1)
            return;

        int op_idx = nums.size() - 1;
        while (op_idx > 0 && nums[op_idx-1] >= nums[op_idx])
            op_idx--;

        if(op_idx != 0)
        {
            int ex_idx = op_idx;
            while (ex_idx < nums.size() && nums[ex_idx] > nums[op_idx-1])
                ex_idx++;
            int tmp = nums[ex_idx-1];
            nums[ex_idx-1] = nums[op_idx-1];
            nums[op_idx-1] = tmp;
        }

        sort(nums.begin()+op_idx, nums.end());
        return;
    }
};

