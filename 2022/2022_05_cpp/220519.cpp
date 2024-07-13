//
// Created by z on 2022/5/23.
// # 329

class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {

        int final_ret = -1, m = matrix.size(), n = matrix[0].size();
        std::vector<std::vector<int>> ans(m, std::vector<int>(n, 0));
        int dr[] = {-1, 0, 0, 1}, dc[] = {0, -1, 1, 0};

        std::function<int(int, int)> dfs = [&] (int r, int c) -> int {

            int ret = ans[r][c], v = matrix[r][c];
            if (ret)
                return ret;
            cout << "search " << r << " " << c << "  v=" << v << endl;
            for (int i = 0; i < 4; i++) {

                int nr = r + dr[i], nc = r + dc[i];

                if (nr >= 0 && nr < m && nc >= 0 && nc < n) {
                    int nv = matrix[nr][nc];cout <<"nv=" << nv;
                    if (nv <= v)
                        continue;
                    else {
                        cout << "search nv";
                        int nans = dfs(nr, nc);
                        ret = ret > nans ? ret : nans;
                    } cout << endl;
                }
            }

            ret++;
            ans[r][c] = ret;
            return ret;
        };

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                int x;
                if (ans[i][j]) {
                    x = ans[i][j];
                } else {
                    x = dfs(i, j);
                }
                // cout << x << " ";
                final_ret = final_ret > x ? final_ret : x;
            }

            cout << endl;
        }

        return final_ret;
    }
};
