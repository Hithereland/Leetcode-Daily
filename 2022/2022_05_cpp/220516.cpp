//
// Created by z on 2022/5/23.
// # 1091

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {

        int r = grid.size(), c = grid[0].size();
        if (grid[r-1][c-1] + grid[0][0])
            return -1;

        std::queue<std::pair<int, int>> loc;
        std::queue<int> step;

        step.push(1);
        loc.push({0, 0});
        grid[0][0] = 0;

        std::vector<int>
                dr = {-1, -1, -1, 0, 0, 1, 1, 1},
                dc = {-1, 0, 1, -1, 1, -1, 0, 1};

        while (loc.size()) {

            auto p = loc.front();
            int t_step = step.front();

            loc.pop(); step.pop();

            if (p.first == r-1 && p.second == c-1)
                return t_step;

            for (int i = 0; i < 8; i++) {

                int next_r = p.first + dr[i], next_c = p.second + dc[i];
                if (next_r >= 0 && next_r < r && next_c >= 0 && next_c < c && grid[next_r][next_c] == 0) {

                    loc.push({next_r, next_c});
                    step.push(t_step+1);

                    grid[next_r][next_c] = 1;
                }
            }
        }

        return -1;
    }
};
