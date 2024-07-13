//
// Created by z on 5/15/2022.
// # 743

class Solution {
public:

    struct cmp {
        bool operator()(std::pair<int, int> a, std::pair<int, int> b) {
            return a.second > b.second;
        };
    };

    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        int ret = 0;
        std::unordered_map<int, int> m;
        std::vector<std::vector<std::pair<int, int>>> g(n, std::vector<std::pair<int, int>>());
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, cmp> q;

        for (auto v: times) {

            int node = v[0] - 1;
            g[node].push_back({v[1]-1, v[2]});
        }

        q.push({k-1, 0});


        while (q.size() > 0) {

            std::pair<int, int> p = q.top();
            q.pop();

            int node = p.first, time = p.second;
            if (m.find(node) != m.end()) {
                continue;
            }
            m[node] = 1;

            ret = ret > time ? ret : time;

            for (auto &nextp: g[node]) {

                int nextnode = nextp.first, nexttime = time + nextp.second;
                q.push({nextnode, nexttime});
            }
        }

        cout << m.size() << endl;
        if (m.size() == n)
            return ret;
        else
            return -1;
    }
};

