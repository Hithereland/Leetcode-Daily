//
// Created by z on 4/12/2022.
// # 289

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        vector<int> delta = {-1, 0, 1};
        vector<int> ans;
        for (int i = 0; i < board.size(); i++)
            for (int j = 0; j < board[0].size(); j++)
            {
                int num = 0;
                for (int dx: delta)
                    for (int dy: delta)
                    {
                        if (dx == 0 && dy == 0)
                            continue;
                        int r = dx+i, c = dy+j;
                        if (r < 0 || r > board.size()-1 ||
                            c < 0 || c > board[0].size()-1)
                            continue;
                        num += board[r][c];
                    }
                int tmp = 0;
                if (num < 2 || num > 3) ;
                if (num == 2)
                    tmp = board[i][j];
                if (num == 3)
                    tmp = 1;

                ans.push_back(tmp);
            }

        int idx = 0;
        for (auto &r: board)
            for (auto &c: r)
            {
                c = ans[idx];
                idx++;
            }
        return;
    }
};

