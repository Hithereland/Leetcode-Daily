//
// Created by z on 4/7/2022.
// # 1046

class Solution {
public:

    int lastStoneWeight(vector<int>& stones) {

        priority_queue<int, vector<int>, less<int> > q;
        for (auto &x: stones)
            q.push(x);

        while (q.size() > 1)
        {
            int a = q.top(); q.pop();
            int b = q.top(); q.pop();
            int c = a - b;
            if (c != 0)
                q.push(c);
        }

        if (q.size())
            return q.top();
        else
            return 0;
    }
};

