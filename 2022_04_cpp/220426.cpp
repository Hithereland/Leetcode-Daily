//
// Created by z on 4/27/2022.
// # 1584

class Solution {
public:

    int minCostConnectPoints(vector<vector<int>>& points) {

        size_t n = points.size(), ret = 0;
        std::vector<int> dist(n), flag(n, 0);
        std::vector<std::vector<int>> graph(n, std::vector<int>(n));

        for (int i = 0; i < n; i++)
            for (int j = i; j < n; j++) {

                graph[i][j] = graph[j][i] =
                        std::abs(points[i][0] - points[j][0]) + std::abs(points[i][1] - points[j][1]);
            }


        flag[0] = 1;
        for (int i = 0; i < n; i++) {

            dist[i] = graph[0][i];
        }


        while (1) {

            int minDist = 114514191;
            int nextIn  = -1;

            for (int i = 0; i < n; i++) {

                if (flag[i] == 0 && dist[i] < minDist) {
                    minDist = dist[i];
                    nextIn  = i;
                }
            }

            if (nextIn == -1)
                break;

            flag[nextIn] = 1;
            ret += minDist;

            for (int i = 0; i < n; i++) {

                dist[i] = min(dist[i], graph[nextIn][i]);
            }
        }

        return ret;

    }
};

