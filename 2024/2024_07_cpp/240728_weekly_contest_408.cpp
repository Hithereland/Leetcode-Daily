// Weekly Contest 407
// https://leetcode.com/contest/weekly-contest-407/

#include <cmath>
#include <vector>

class Solution_A
{
  public:
    bool canAliceWin(std::vector<int> &nums)
    {

        int s_sum = 0, sum = 0;
        for (auto &x : nums) {
            sum += x;
            s_sum += x < 10 ? x : 0;
        }
        return s_sum * 2 == sum;
    }
};

class Solution_B
{
  public:
    int nonSpecialCount(int l, int r)
    {
        std::vector<int> p;

        if (r < 4) {
            return r - l + 1;
        }

        p.push_back(2);
        int tmp = 2;
        int ans = 0, l_ans = 0;

        int p_idx = 0;

        while (((long long)(p[p.size() - 1]) * (long long)(p[p.size() - 1]))
               <= (long long)(r))
        {
            tmp++;
            bool is_prime = true;
            for (auto &pp : p) {
                if (tmp % pp == 0) {
                    is_prime = false;
                }
                if (pp * pp > tmp)
                    break;
            }
            if (is_prime) {
                p.push_back(tmp);
            }
        }

        for (int i = 0; i < p.size(); i++) {
            long long xxx = (long long)(p[i]) * (long long)(p[i]);
            if (xxx <= (long long)(r) && xxx >= (long long)(l)) {
                ans++;
            }
        }
        return r - l + 1 - ans;
    }
};

class Solution_B_Better
{
  public:
    int nonSpecialCount(int l, int r)
    {

        int n = std::sqrt(r) + 1;

        // Euler
        std::vector<int> primes;
        std::vector<bool> not_prime(n + 1);
        for (int i = 2; i <= n; i++) {
            if (!not_prime[i]) {
                primes.push_back(i);
            }
            for (auto &p : primes) {
                if (p * i > n) {
                    break;
                }
                not_prime[p * i] = true;
                if (i % p == 0) {
                    // Means i == (p_a1 * p_a2 * ...) * p
                    // let p_min = min(p_a1, p_a2, ..., p)
                    // for a bigger prime p_next
                    // p_next * i will be judged later
                    // as (i_next == p_next * (i / p_min)) * p_min
                    break;
                }
            }
        }

        int special = 0;
        for (auto &p : primes) {
            int num = p * p;
            if (num <= r && num >= l) {
                special++;
            }
        }

        return r - l + 1 - special;
    }
};

int main()
{
    Solution_B_Better s;
    s.nonSpecialCount(4, 16);
}