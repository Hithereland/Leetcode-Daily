//
// Created by z on 5/8/2022.
// # 1631

class Solution {
public:

    static int valid(vector<vector<int>>& h, int ans) {

        int r = h.size(), c = h[0].size();
        std::vector<vector<bool>> flag(r, std::vector<bool>(c, 0));
        flag[0][0] = 1;
        typedef std::pair<int, int> pos;

        int dr[] = {1, 0, -1, 0};
        int dc[] = {0, 1, 0, -1};

        std::function<int(pos)> dfs = [&] (pos p) -> int {

            int rr = p.first, cc = p.second, ret = 0;
            if (rr == r-1 && cc == c-1)
                return 1;

            for (int i = 0; i < 4; i++) {

                int nr = rr + dr[i], nc = cc + dc[i];
                if ((nr >= 0) && (nr < r) && (nc >= 0) && (nc < c) && (flag[nr][nc] == 0)
                    && (abs(h[nr][nc] - h[rr][cc]) <= ans)) {

                    flag[nr][nc] = 1;
                    ret = dfs(pos(nr, nc));
                }
                if (ret) return 1;
            }

            return 0;
        };

        return dfs(pos(0, 0));
    }



    int minimumEffortPath(vector<vector<int>>& heights) {

        int highest = -1, lowest = 11451419;
        for (auto &v: heights)
            for (auto &i: v) {

                highest = max(highest, i);
                lowest  = min(lowest,  i);
            }

        int l = 0, r = highest - lowest;

        while (l < r) {

            int m = (l + r) / 2;

            int v = valid(heights, m);

            if (v) {
                r = m;
            } else {
                l = m + 1;
            }
        }

        return r;
    }
};