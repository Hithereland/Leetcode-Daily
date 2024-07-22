// Weekly Contest 407
// https://leetcode.com/contest/weekly-contest-407/

#include <limits.h>
#include <vector>
#include <unordered_set>
#include <string>
#include <cstdlib>

class Solution_A
{
  public:
    int minChanges(int n, int k)
    {
        int _xor = n ^ k, ret = 0;
        while (_xor) {
            if (_xor % 2) {
                if (n % 2 == 0) {
                    return -1;
                }
                ret++;
            }
            _xor /= 2;
            n /= 2;
        }

        return ret;
    }
};

class Solution_B
{
  public:
    bool doesAliceWin(std::string s)
    {
        std::unordered_set<char> st = {'a', 'e', 'i', 'o', 'u'};
        for (auto &x : s) {
            if (st.find(x) != st.end()) {
                return true;
            }
        }
        return false;
    }
};

class Solution_C
{
  public:
    int maxOperations(std::string s)
    {
        int ret = 0, tmp_ones = 0, mode = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '1') {
                mode = 1;
                tmp_ones++;
            } else {
                // s[i] == '0'
                if (mode == 1) {
                    ret += tmp_ones;
                }
                mode = 0;
            }
        }
        return ret;
    }
};

class Solution_D
{
  public:
    long long minimumOperations(std::vector<int> &nums,
                                std::vector<int> &target)
    {
        long long prev_change = 0;
        long long ret         = 0;

        for (int i = 0; i < nums.size(); i++) {
            long long curr_change = nums[i] - target[i];
            if ((prev_change ^ curr_change) < 0) {
                prev_change = curr_change;
                ret += std::abs(curr_change);
            } else {
                if (std::abs(curr_change) > std::abs(prev_change)) {
                    ret += std::abs(curr_change - prev_change);
                }
                prev_change = curr_change;
            }
        }

        return ret;
    }
};

int main()
{
    int a = 1;
    return 0;
}