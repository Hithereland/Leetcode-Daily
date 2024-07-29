// 1395. Count Number of Teams
// Medium
// https://leetcode.com/problems/count-number-of-teams/

#include <algorithm>
#include <vector>

class Solution
{
    std::vector<int> left, right;
    void insert(std::vector<int> &v, int val)
    {
        v.insert(std::lower_bound(v.begin(), v.end(), val), val);
    }

    void remove(std::vector<int> &v, int val)
    {
        v.erase(std::lower_bound(v.begin(), v.end(), val));
    }

    // count num of elements less than
    int cnt_lt(std::vector<int> &v, int val)
    {
        return std::lower_bound(v.begin(), v.end(), val) - v.begin();
    }

    // greater than
    int cnt_gt(std::vector<int> &v, int val)
    {
        return v.end() - std::lower_bound(v.begin(), v.end(), val);
    }

  public:
    int numTeams(std::vector<int> &rating)
    {
        if (rating.size() < 3) {
            return 0;
        }

        int ret = 0;
        right   = std::vector<int>(rating.begin() + 1, rating.end());
        sort(right.begin(), right.end());
        for (int mid = 1; mid < rating.size() - 1; mid++) {
            insert(left, rating[mid - 1]);
            remove(right, rating[mid]);
            int val = rating[mid];
            ret += cnt_lt(left, val) * cnt_gt(right, val);
            ret += cnt_gt(left, val) * cnt_lt(right, val);
        }

        return ret;
    }
};

int main()
{
    std::vector<int> v = {2, 5, 3, 4, 1};
    Solution s;
    auto x = s.numTeams(v);
    x++;
}