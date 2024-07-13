// 118
// https://leetcode.com/problems/pascals-triangle

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ret;
        ret.push_back(vector<int>(1, 1));
        for (int i = 2; i <= numRows; i++) {
            vector<int> tmp(i);
            tmp[0] = tmp[i-1] = 1;
            for (int j = 1; j < i-1; j++) {
                tmp[j] = ret[i-2][j] + ret[i-2][j-1];
            }
            ret.push_back(std::move(tmp));
        }
        return ret;
    }
};