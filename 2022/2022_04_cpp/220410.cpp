//
// Created by z on 4/10/2022.
// # 682

class Solution {
public:
    int calPoints(vector<string>& ops) {
        int ret = 0;
        vector<int> sc;
        for (auto &x: ops)
        {
            int num = atoi(x.c_str());
            if (num != 0)
                sc.push_back(num);
            else
            {
                if (x == "+")
                    sc.push_back(sc[sc.size()-1] + sc[sc.size()-2]);
                if (x == "D")
                    sc.push_back(sc[sc.size()-1]*2);
                if (x == "C")
                    sc.pop_back();
                if (x == "0")
                    sc.push_back(0);
            }
        }
        for (auto &x: sc)
            ret += x;
        return ret;
    }
};

