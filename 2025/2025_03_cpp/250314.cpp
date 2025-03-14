// 2226. Maximum Candies Allocated to K Children
// Medium
// https://leetcode.com/problems/maximum-candies-allocated-to-k-children/

#include <algorithm>
#include <vector>

class Solution
{
public:
    bool check(std::vector<int> &candies, int ans, long long k) {
        if (ans == 0) return true;

        long long cnt = 0;
        for (auto &pile : candies) {
            cnt += pile / ans;
        }
        return cnt >= k;
    }

    int maximumCandies(std::vector<int> &candies, long long k) {
        int l = 0, r = candies[0];
        for (auto &p : candies) {
            r = std::max(r, p);
        }

        while (l < r) {
            int m = (l + r) / 2;
            if (check(candies, m, k)) {
                l = m + 1;
            } else {
                r = m;
            }
        }
        if (check(candies, l, k)) {
            return l;
        } else {
            return l - 1;
        }
    }
};