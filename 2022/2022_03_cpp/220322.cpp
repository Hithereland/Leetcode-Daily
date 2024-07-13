//
// Created by z on 3/22/2022.
// # 1663

class Solution {
public:
    string getSmallestString(int n, int k) {

        string ret(n,'a');
        k -= n;
        int opidx = ret.size()-1;

        while (k)
        {
            if (k >= 25)
            {
                ret[opidx] += 25;
                k -= 25;
                opidx--;
            }
            else
            {
                ret[opidx] += k;
                k = 0;
            }
        }

        return ret;

    }
};
