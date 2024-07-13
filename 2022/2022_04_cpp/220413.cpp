//
// Created by z on 4/13/2022.
// # 59

class Solution {
public:
        
    vector<vector<int>> generateMatrix(int n) {
        unordered_map<int, int> flag;
        vector<vector<int>> ret;
        for (int i = 0; i < n; i++)
        {
            vector<int> tmp(n,0);
            ret.push_back(tmp);
        }
        int r = 0, c = 0, d = 0, num = 1;
        while (num <= n*n)
        {
            ret[r][c] = num;
            num++;
            flag[r*n+c] = 1;
            int nr = r + (d%2 ? (1 - ((d/2)<<1)) : 0);
            int nc = c + (d%2 ? 0 : (1 - ((d/2)<<1)));
            if (flag.find(nr*n+nc) != flag.end() || nr >= n || nc >= n)
            {
                d++;
                d %= 4;
                nr = r + (d%2 ? (1 - ((d/2)<<1)) : 0);
                nc = c + (d%2 ? 0 : (1 - ((d/2)<<1)));
            }
            r = nr;
            c = nc;
        }
        return ret;
    }
};
