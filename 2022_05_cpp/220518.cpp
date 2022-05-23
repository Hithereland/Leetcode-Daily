//
// Created by z on 2022/5/23.
// # 1192

class Solution {
public:

    struct PairHash {

        template<typename T1, typename T2>
        std::size_t operator()(const std::pair<T1, T2>& p) const {

            return std::hash<T1>()(p.first) ^ std::hash<T2>()(p.second);
        }
    };


    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {

        std::unordered_map<std::pair<int, int>, int, PairHash> ret_map;

        for (int i = 0; i < connections.size(); i++)
            std::sort(connections[i].begin(), connections[i].end());

        for (auto x: connections)
            ret_map[{x[0], x[1]}] = 1;


        std::vector<std::vector<int>> aj(n, std::vector<int>());

        for (auto x: connections) {

            aj[x[0]].push_back(x[1]);
            aj[x[1]].push_back(x[0]);
        }


        std::vector<int> low(n, -1), pre(n, -1), vis(n, 0);
        int dfs_clk = 0;


        std::function<int(int, int)> dfs = [&] (int u, int fa) -> int {

            pre[u] = dfs_clk++;
            int lowu = dfs_clk;

            for (auto v: aj[u]) {

                if (vis[v] == 0) {

                    vis[v] = 1;
                    int lowv = dfs(v, u);
                    lowu = lowv < lowu ? lowv : lowu;

                    if (lowv > pre[u]) {

                        int ln = u, bn = v;
                        if (ln > bn) {
                            ln = v; bn = u;
                        }

                        ret_map[{ln, bn}] = 0;
                    }

                } else {

                    if (pre[v] < pre[u] && v != fa) {
                        lowu = pre[v] < lowu ? pre[v] : lowu;
                    }
                }
            }

            low[u] = lowu;
            return lowu;
        };

        dfs(0, -1);

        std::vector<std::vector<int>> ret;
        for (auto p: ret_map) {

            if (p.second == 0) {
                ret.push_back({p.first.first, p.first.second});
            }
        }

        return ret;
    }
};
