// 2503. Maximum Number of Points From Grid Queries
// Hard
// https://leetcode.com/problems/maximum-number-of-points-from-grid-queries/

#include <queue>
#include <utility>
#include <vector>

class Solution
{
    typedef struct pos {
        int val, r, c;
    } pos;

    struct cmp {
        bool operator()(pos a, pos b) {
            return a.val > b.val;
        }
    };

public:
    std::vector<std::pair<int, int>> oneQuery(std::vector<std::vector<int>> &grid) {
        int n = grid.size(), m = grid[0].size();
        int dr[] = {0, 0, -1, 1};
        int dc[] = {-1, 1, 0, 0};

        std::vector<std::pair<int, int>> ret;
        std::vector<std::vector<bool>> vis = std::vector<std::vector<bool>>(n, std::vector<bool>(m, false));
        std::priority_queue<pos, std::vector<pos>, cmp> pq;

        int greater = 0, cnt = 0;
        pq.push({grid[0][0], 0, 0});
        vis[0][0] = true;

        while (!pq.empty()) {
            pos tmp = pq.top();

            if (greater > tmp.val) {
                pq.pop();
                cnt += 1;
                for (int i = 0; i < 4; i++) {
                    int nr = tmp.r + dr[i];
                    int nc = tmp.c + dc[i];

                    if (nr < n && nr >= 0 && nc < m && nc >= 0 && !vis[nr][nc]) {
                        pq.push({grid[nr][nc], nr, nc});
                        vis[nr][nc] = true;
                    }
                }
            } else {
                ret.push_back({greater, cnt});
                greater = tmp.val + 1;
            }
        }

        ret.push_back({greater, cnt});
        return ret;
    }

    int getCnt(std::vector<std::pair<int, int>> &list, int q) {
        int l = 0, r = list.size() - 1;
        while (l < r) {
            int m = (l + r) / 2;
            if (list[m].first < q) {
                l = m + 1;
            } else {
                r = m;
            }
        }

        // l == r now
        if (list[l].first > q) {
            return list[l - 1].second;
        } else {
            return list[l].second;
        }
    }

    std::vector<int> maxPoints(std::vector<std::vector<int>> &grid, std::vector<int> &queries) {
        auto list = oneQuery(grid);
        std::vector<int> ret;

        for (auto &q : queries) {
            ret.push_back(getCnt(list, q));
        }

        return ret;
    }
};