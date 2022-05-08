//
// Created by z on 5/8/2022.
// # 399

class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {

        std::unordered_map<string, int> sToNode;
        int n = 0;

        for (auto x: equations)
            for (auto y: x)
                if (sToNode.find(y) ==sToNode.end()) {
                    sToNode[y] = n;
                    n++;
                } else
                    continue;

        std::vector<vector<double>> g(n, std::vector<double>(n, 0));
        std::vector<vector<int>> al(n, std::vector<int>(0));

        for (int i = 0; i < equations.size(); i++) {

            auto &x = equations[i];
            int a = sToNode[x[0]], b = sToNode[x[1]];
            g[a][b] = values[i];
            g[b][a] = 1.0 / values[i];
        }

        for (int i = 0; i < n; i++)
            for (int j = i+1; j < n; j++) {

                if (g[i][j] != 0.0) {
                    al[i].push_back(j);
                    al[j].push_back(i);
                }
            }



        vector<double> ret;

        for (int idx = 0; idx < queries.size(); idx++) {

            string src_str = queries[idx][0], tgt_str = queries[idx][1];
            if (sToNode.find(src_str) == sToNode.end() ||
                sToNode.find(tgt_str) == sToNode.end()) {

                ret.push_back(-1); continue;
            }

            int s = sToNode[src_str], t = sToNode[tgt_str];
            std::unordered_set<int> flag = {s};
            std::vector<int> path = {s};

            std::function<bool(int)> dfs = [&] (int x) -> bool {

                if (x == t)
                    return 1;

                for (auto &nx: al[x]) {

                    if (flag.find(nx) == flag.end()) {
                        flag.insert(nx);
                        path.push_back(nx);
                        if (dfs(nx))
                            return 1;
                        else
                            path.pop_back();
                    }
                }

                return 0;
            };

            if (dfs(s) == 0) {
                ret.push_back(-1);
            } else {

                double ans = 1.0;
                for (int i = 0; i < path.size()-1; i++) {

                    ans *= g[path[i]][path[i+1]];
                }
                ret.push_back(ans);
            }
        }

        return ret;
    }
};

