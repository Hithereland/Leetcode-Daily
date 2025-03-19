// 2610. 转换二维数组
// Medium
// https://leetcode.cn/problems/convert-an-array-into-a-2d-array-with-conditions/

#include <unordered_map>
#include <vector>

class Solution
{
public:
    std::vector<std::vector<int>> findMatrix(std::vector<int> &nums) {
        std::unordered_map<int, int> num_to_cnt;

        for (auto &x : nums) {
            num_to_cnt[x] += 1;
        }

        std::vector<std::vector<int>> ret;
        for (auto &p : num_to_cnt) {
            int num = p.first, cnt = p.second;
            for (int i = 0; i < cnt; i++) {
                if (i == ret.size()) {
                    ret.push_back({});
                }
                ret[i].push_back(num);
            }
        }

        return ret;
    }
};