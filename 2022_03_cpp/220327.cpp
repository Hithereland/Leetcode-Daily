//
// Created by z on 3/27/2022.
// # 1337

class Solution {
public:

    typedef pair<int, int> p;

    static bool cmp (p a, p b)
    {
        return a.first != b.first ? a.first < b.first : a.second < b.second;
    }


    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<p> soldiers(mat.size(), p(0,0));
        for (int i = 0; i < mat.size(); i++)
        {
            int num = 0;
            for (int j = 0; j < mat[0].size(); j++)
            {
                if (mat[i][j] == 1)
                    num++;
                else
                    break;
            }
            soldiers[i].first  = num;
            soldiers[i].second = i;
        }
        sort(soldiers.begin(), soldiers.end(), cmp);

        vector<int> ret;
        for (int i = 0; i < k; i++)
        {
            ret.push_back(soldiers[i].second);
        }
        return ret;
    }
};