//
// Created by z on 5/13/2022.
// # 216

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {

        std::vector<vector<int>> ret;
        std::vector<int> tmp;

        std::function<void(int, int, int)> solve = [&] (int idx, int target, int step_remain) -> void {

            if (step_remain == 0 && target == 0) {
                ret.push_back(tmp);
                return;
            }

            for (int i = idx; i < 10; i++) {
                int next_idx = i+1, next_step = step_remain - 1;
                int next_min = next_idx * next_step + (next_step*(next_step-1))/2;
                int next_max = ((9+9-next_step+1) * next_step) >> 1;

                if (next_min <= target - i && next_max >= target - i) { // if ..., there might be valid solution
                    tmp.push_back(i);                                   // (i) is chosen to be one part of one ans
                    solve(next_idx, target - i, next_step);             // (target - i) is the next target
                    tmp.pop_back();
                }
            }

            return;
        };

        solve(1, n, k);

        return ret;
    }
};

