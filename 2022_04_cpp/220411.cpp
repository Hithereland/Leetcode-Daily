//
// Created by z on 4/11/2022.
// # 1260
// 100题纪念！
class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        vector<vector<int>> ret;
        for (int i = 0; i < grid.size(); i++)
        {
            vector<int> tmp(grid[0].size(), 0);
            ret.push_back(tmp);
        }
        for (int r = 0; r < grid.size(); r++)
            for (int c = 0; c < grid[0].size(); c++)
            {
                int idx = r * grid[0].size() + c + k;
                idx %= grid.size()*grid[0].size();
                int rr = idx / grid[0].size();
                int cc = idx % grid[0].size();
                ret[rr][cc] = grid[r][c];
            }
        return ret;
    }
};

