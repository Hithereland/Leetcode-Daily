// Build a Matrix With Conditions
// Hard
// https://leetcode.com/problems/build-a-matrix-with-conditions/

#include <limits.h>
#include <queue>
#include <utility>
#include <vector>

class Solution
{
  public:
    // Ignore cases where duplicate elements exist in the 'discrpts'
    std::vector<std::pair<int, int>>
    topoSort(int k, std::vector<std::vector<int>> &discrpts)
    {
        // graph[i][0] represents node i's indegree
        // graph[i][k] = j (k>0) means node j is a successor of node i
        auto graph = std::vector<std::vector<int>>(k + 1, {0});
        for (auto &d : discrpts) {
            graph[d[0]].push_back(d[1]);
            graph[d[1]][0]++;
        }

        // Build array in topo-order
        std::vector<std::pair<int, int>> ret;
        std::queue<int> q;
        for (int i = 1; i < graph.size(); i++) {
            if (graph[i][0] == 0) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            int tmp = q.front();
            q.pop();
            ret.push_back({tmp, ret.size()});
            for (int i = 1; i < graph[tmp].size(); i++) {
                int sub = graph[tmp][i];
                if (graph[sub][0] == 0) {
                    // Reach here means there is a loop in the graph
                    return {};
                } else {
                    graph[sub][0]--;
                }

                if (graph[sub][0] == 0) {
                    q.push(sub);
                }
            }
        }

        sort(ret.begin(), ret.end(),
             [](std::pair<int, int> a, std::pair<int, int> b) -> bool {
                 return a.first < b.first;
             });
        return ret;
    }

    std::vector<std::vector<int>>
    buildMatrix(int k, std::vector<std::vector<int>> &rowConditions,
                std::vector<std::vector<int>> &colConditions)
    {
        auto row_topo_order = topoSort(k, rowConditions),
             col_topo_order = topoSort(k, colConditions);
        if (row_topo_order.size() != k || col_topo_order.size() != k) {
            return {};
        }

        std::vector<std::vector<int>> ret(k, std::vector<int>(k, 0));
        for (int i = 0; i < k; i++) {
            int num = i + 1, row = row_topo_order[i].second,
                col       = col_topo_order[i].second;
            ret[row][col] = num;
        }

        return ret;
    }
};