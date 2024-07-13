//
// Created by z on 3/25/2022.
// # 1029

class Solution {
public:

    static bool cmp(vector<int> a, vector<int> b) {
        return (a[0] - a[1]) < (b[0] - b[1]);
    }

    int twoCitySchedCost(vector<vector<int>> costs) {
        sort(costs.begin(), costs.end(), cmp);
        int ret = 0;
        for (int i = 0; i < costs.size(); i++)
        {
            ret += costs[i][i>=(costs.size()/2)];
        }
        return ret;
    }
};

