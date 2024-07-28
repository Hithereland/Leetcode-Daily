// 2045. Second Minimum Time to Reach Destination
// Hard
// https://leetcode.com/problems/second-minimum-time-to-reach-destination/

#include <vector>
#include <queue>

class Solution
{
  public:
    int secondMinimum(int n, std::vector<std::vector<int>> &edges, int time,
                      int change)
    {
        // build graph
        std::vector<std::vector<int>> g(n + 1);
        for (auto &e : edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }

        // BFS with little trick
        std::queue<std::pair<int, int>> q;
        std::vector<int> arrv_t(n + 1), visited_times(n + 1);
        q.push({1, 0});
        visited_times[1] = 1;

        while (!q.empty()) {
            auto curr_node_info = q.front();
            int curr_node       = curr_node_info.first,
                curr_arrv_t     = curr_node_info.second;
            q.pop();

            for (auto &next_node : g[curr_node]) {
                int next_arrv_t =
                    (curr_arrv_t / change) % 2 == 0
                        ? curr_arrv_t + time
                        : (change - curr_arrv_t % change) + curr_arrv_t + time;
                if (next_arrv_t == arrv_t[next_node]
                    || visited_times[next_node] >= 2)
                {
                    // do nothing
                } else {
                    visited_times[next_node]++;
                    arrv_t[next_node] = next_arrv_t;
                    q.push({next_node, next_arrv_t});
                }

                if (next_node == n && visited_times[next_node] == 2) {
                    return next_arrv_t;
                }
            }
        }

        return 0;
    }
};