//
// Created by z on 5/8/2022.
// # 785

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {

        int n = graph.size();
        std::unordered_set<int> remain;
        std::unordered_map<int, bool> mp;
        std::queue<int> q;
        for (int i = 1; i < n; i++)
            remain.insert(i);
        q.push(0);
        mp[0] = 0;


        while (q.size()) {

            int v = q.front();
            q.pop();
            bool inPart1 = mp[v];
            int loop = 1;
            for (auto &nv: graph[v]) {

                if (mp.find(nv) == mp.end()) {
                    mp[nv] = !inPart1;
                    q.push(nv);
                    remain.erase(nv);
                } else {
                    if (mp[nv] == inPart1)
                        return 0;
                    else
                        continue;
                }

            }

            if (q.size() == 0 && mp.size() < n) {
                int tmp = *remain.begin();
                remain.erase(tmp);
                q.push(tmp);
            }
        }

        return 1;
    }
};

