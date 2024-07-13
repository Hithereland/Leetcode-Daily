//
// Created by z on 4/5/2022.
// # 11

class Solution {
public:
    int maxArea(vector<int>& height) {
        vector<int> &x = height;
        int l = 0, r = x.size()-1, ans = -1;
        while (l < r)
        {
            int tmp = (x[l] < x[r] ? x[l] : x[r]) * (r-l);
            ans = ans > tmp ? ans : tmp;

            if (x[l] < x[r])
                l++;
            else if (x[l] > x[r])
                r--;
            else
            {
                l++;
                r--;
            }
        }
        return ans;
    }
};

