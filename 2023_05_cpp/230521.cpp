// No. 934
// https://leetcode.com/problems/shortest-bridge/

class Solution {
public:
    int shortestBridge(vector<vector<int>>& grid) {
        queue<pair<int, int>> bfs_q;
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};
        
        function<bool(int)> validr = [&] (int r) {
            return r < grid.size() && r >= 0;
        };
        
        function<bool(int)> validc = [&] (int c) {
            return c < grid[0].size() && c >= 0;
        };
        
        function<void(int, int)> init_bfs_q = [&] (int r, int c) {
            bfs_q.push({r, c});
            grid[r][c] = 2;
            for (int i = 0; i < 4; i++) {
                int nr = dr[i] + r, nc = dc[i] + c;
                if (validr(nr) && validc(nc) && grid[nr][nc] == 1) {
                     init_bfs_q(nr, nc);
                }
            }
        };
        
        for (int i = 0; i < grid.size(); i++)
            for (int j = 0; j < grid[0].size(); j++)
                if (grid[i][j] == 1) {
                    init_bfs_q(i, j);
                    goto brk;
                }
        
brk:
        int q_sz = bfs_q.size();
        int ans = 0;
        while (!bfs_q.empty()) {
            ans++;
            int q_size = bfs_q.size();
            for (int i = 0; i < q_size; i++) {
                int r = bfs_q.front().first, c = bfs_q.front().second;
                bfs_q.pop();
                for (int j = 0; j < 4; j++) {
                    int nr = dr[j] + r, nc = dc[j] + c;
                    if (validr(nr) && validc(nc)) {
                        if (grid[nr][nc] == 0) {
                            grid[nr][nc] = 2;
                            bfs_q.push({nr, nc});
                        } else if (grid[nr][nc] == 1) {
                           goto found;
                        }
                    }
                }
            }
        }
found:
        return ans-1;
    }
};