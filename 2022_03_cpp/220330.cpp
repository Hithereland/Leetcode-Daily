//
// Created by z on 3/30/2022.
// # 78
// O(log n + log m)... maybe
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rn = matrix.size(), cn = matrix[0].size();
        int l = 0, r = rn * cn - 1;

        while (l <= r)
        {
            int m = (l+r) / 2;
            int x = matrix[m/cn][m%cn];
            if (x > target)
                r = m-1;
            else if (x < target)
                l = m+1;
            else
                return 1;
        }

        return 0;
    }
};