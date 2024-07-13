//
// Created by z on 3/31/2022.
// # 410
// So hard that I did not figure it out with my own effort.
// And no python solution today.
class Solution {
public:

    bool check(vector<int>& x, int ans, int n)
    {
        int ng = 0, tmp = 0; // n groups
        for (int i = 0; i < x.size(); i++)
        {
            if (tmp + x[i] > ans)
            {
                if (x[i] > ans)
                    return 0;
                tmp = x[i];
                ng++;
            }
            else
            {
                tmp += x[i];
            }
        }
        if (ng < n)
            return 1;
        else
            return 0;
    }


    int splitArray(vector<int>& nums, int m) {
        int l = 0, r = accumulate(nums.begin(), nums.end(), 0);

        while (l < r)
        {
            int ans = (l + r) / 2;
            if (check(nums, ans, m))
                r = ans;
            else
                l = ans+1;
        }
        return r;
    }
};

