//
// Created by z on 5/13/2022.
// # 47

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {

        int n = nums.size();

        std::vector<int> flag(21, 0);
        std::vector<std::vector<int>> ret;
        std::vector<int> tmp;

        for (auto &x: nums) {
            flag[x+10]++;
        }

        std::function<void()> dfs = [&] () {

            if (tmp.size() == n) {
                ret.push_back(tmp);
                return;
            }

            for (int i = 0; i < 21; i++) {

                if (flag[i] == 0)
                    continue;
                int ins = i - 10;
                tmp.push_back(ins);
                flag[i]--;
                dfs();
                flag[i]++;
                tmp.pop_back();
            }
        };

        dfs();

        return ret;
    }
};

