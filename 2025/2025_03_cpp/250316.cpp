// 2594. Minimum Time to Repair Cars
// Medium
// https://leetcode.com/problems/minimum-time-to-repair-cars/

#include <cmath>
#include <vector>

class Solution
{
public:
    bool canRepair(std::vector<int> &ranks, int cars, long long time) {
        int most_repair_cnt = 0;
        for (auto &r : ranks) {
            most_repair_cnt += (int)sqrt(time / r);
            // may result in runtime error...
            if (most_repair_cnt >= cars) {
                return true;
            }
        }
        return most_repair_cnt >= cars;
    }

    long long repairCars(std::vector<int> &ranks, int cars) {
        long long l = 0, r = (long long)cars * (long long)cars * (long long)ranks[0];
        while (l < r) {
            long long m = (l + r) / 2;
            if (canRepair(ranks, cars, m)) {
                r = m;
            } else {
                l = m + 1;
            }
        }
        if (canRepair(ranks, cars, l)) {
            return l;
        } else {
            return l + 1;
        }
    }
};