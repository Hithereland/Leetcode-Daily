//
//
//

#include <vector>
#include <string>

class Solution
{

    // Bigger than 1e6 * 26
    const int INF = 2.7e7;

  public:
    long long minimumCost(std::string source, std::string target,
                          std::vector<char> &original,
                          std::vector<char> &changed, std::vector<int> &cost)
    {
        std::vector<std::vector<std::vector<int>>> floyd_matrices(
            2, std::vector<std::vector<int>>(26, std::vector<int>(26, INF)));

        auto &ini_matrix = floyd_matrices[0];
        for (int i = 0; i < 26; i++) {
            ini_matrix[i][i] = 0;
        }
        for (int i = 0; i < cost.size(); i++) {
            int from = original[i] - 'a', to = changed[i] - 'a',
                &dist = cost[i];

            // It is very STUPID that there are multiple edges between two
            // nodes.
            ini_matrix[from][to] = std::min(ini_matrix[from][to], dist);
        }

        // Floyd Algorithm
        for (int mid = 0; mid < 26; mid++) {
            auto &base_matrix = floyd_matrices[mid % 2],
                 &new_matrix  = floyd_matrices[(mid + 1) % 2];
            for (int from = 0; from < 26; from++)
                for (int to = 0; to < 26; to++) {
                    new_matrix[from][to] =
                        std::min(base_matrix[from][to],
                                 base_matrix[from][mid] + base_matrix[mid][to]);
                    new_matrix[from][to] = std::min(INF, new_matrix[from][to]);
                }
        }

        auto &final_matrix = floyd_matrices[26 % 2];

        long long ret = 0;
        for (int i = 0; i < source.size(); i++) {
            int from = source[i] - 'a', to = target[i] - 'a';
            ret += final_matrix[from][to];

            // Special case
            if (final_matrix[from][to] >= INF)
                return -1;
        }

        return ret;
    }
};

class Solution_One_Matrix_Is_Ok_Too
{

    // Bigger than 1e6 * 26
    const int INF = 2.7e7;

  public:
    long long minimumCost(std::string source, std::string target,
                          std::vector<char> &original,
                          std::vector<char> &changed, std::vector<int> &cost)
    {
        std::vector<std::vector<int>> floyd_matrices(26,
                                                     std::vector<int>(26, INF));

        for (int i = 0; i < 26; i++) {
            floyd_matrices[i][i] = 0;
        }
        for (int i = 0; i < cost.size(); i++) {
            int from = original[i] - 'a', to = changed[i] - 'a',
                &dist = cost[i];

            // It is very STUPID that there are multiple edges between two
            // nodes.
            floyd_matrices[from][to] = std::min(floyd_matrices[from][to], dist);
        }

        // Floyd Algorithm
        for (int mid = 0; mid < 26; mid++) {
            for (int from = 0; from < 26; from++)
                for (int to = 0; to < 26; to++) {
                    floyd_matrices[from][to] = std::min(
                        floyd_matrices[from][to],
                        floyd_matrices[from][mid] + floyd_matrices[mid][to]);
                }
        }

        long long ret = 0;
        for (int i = 0; i < source.size(); i++) {
            int from = source[i] - 'a', to = target[i] - 'a';
            ret += floyd_matrices[from][to];

            // Special case
            if (floyd_matrices[from][to] >= INF)
                return -1;
        }

        return ret;
    }
};