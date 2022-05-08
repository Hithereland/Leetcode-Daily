//
// Created by z on 5/8/2022.
// # 1679

class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {

        std::unordered_map<int, int> m;
        int ret = 0;

        for (auto &x: nums) {
            m[x]++;
        }

        // not equal
        for (auto &p: m) {

            int x = p.first, target = k - p.first;
            if (x >= target) {
                continue;
            } else {
                if (m.find(target) != m.end()) {
                    ret += min(m[x], m[target]);
                } else {
                    continue;
                }
            }
        }

        // equal
        if ((k & 1) == 0) {
            int target = k >> 1;
            ret += m[target] / 2;
        }

        return ret;
    }
};

