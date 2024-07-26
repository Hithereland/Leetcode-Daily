// 1334. Find the City With the Smallest Number of Neighbors at a Threshold
// Distance
// Medium
// https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance

#include <algorithm>
#include <vector>

class Solution
{
  public:
    int findTheCity(int n, std::vector<std::vector<int>> &edges,
                    int distanceThreshold)
    {
        // Floyd
        // distanceThreshold is big enough
        std::vector<std::vector<std::vector<int>>> floyd_matrix(
            2, std::vector<std::vector<int>>(
                   n, std::vector<int>(n, distanceThreshold + 1)));

        for (auto &e : edges) {
            auto &ini_matrix       = floyd_matrix[0];
            ini_matrix[e[0]][e[1]] = e[2];
            ini_matrix[e[1]][e[0]] = e[2];
        }

        for (int mid = 0; mid < n; mid++)
            for (int from = 0; from < n; from++)
                for (int to = from + 1; to < n; to++) {
                    auto &base_matrix = floyd_matrix[mid % 2],
                         &new_matrix  = floyd_matrix[(mid + 1) % 2];
                    int new_dist =
                        std::min(distanceThreshold + 1,
                                 base_matrix[from][mid] + base_matrix[mid][to]);
                    new_matrix[from][to] = new_matrix[to][from] =
                        std::min(base_matrix[from][to], new_dist);
                }

        // Find ans
        auto &final_matrix = floyd_matrix[n % 2];
        // n+1 is big enough
        int ret = 0, min_num_neighbor = n + 1;
        for (int from = 0; from < n; from++) {
            int num_valid_to = 0;
            for (int to = 0; to < n; to++) {
                if (final_matrix[from][to] <= distanceThreshold) {
                    num_valid_to++;
                }
            }
            if (num_valid_to <= min_num_neighbor) {
                ret              = from;
                min_num_neighbor = num_valid_to;
            }
        }

        return ret;
    }
};