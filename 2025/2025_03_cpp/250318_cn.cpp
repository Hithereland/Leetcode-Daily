// 2614. 对角线上的质数
// Easy
// https://leetcode.cn/problems/prime-in-diagonal/description/

#include <cmath>
#include <vector>

// 🤡
class Solution
{
public:
    int diagonalPrime(std::vector<std::vector<int>> &nums) {
        std::vector<bool> not_prime(4e6 + 2, false);
        std::vector<int> primes = {2};

        for (int i = 3; i < not_prime.size(); i++) {
            if (!not_prime[i]) {
                primes.push_back(i);
            }
            for (auto &p : primes) {
                if (p * i >= not_prime.size()) {
                    break;
                }
                not_prime[i * p] = true;
                if (i % p == 0) {
                    break;
                }
            }
        }

        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            int a = nums[i][i], b = nums[i][nums.size() - i - 1];
            if (!not_prime[a]) {
                ans = std::max(ans, a);
            }
            if (!not_prime[b]) {
                ans = std::max(ans, b);
            }
        }

        return ans;
    }
};

// 🎉
class YA_Solution
{
public:
    bool is_prime(int a) {
        if (a == 1) return false;
        if (a == 2) return true;

        for (int i = 2; i * i <= a; i++) {
            if (a % i == 0) {
                return false;
            }
        }
        return true;
    }

    int diagonalPrime(std::vector<std::vector<int>> &nums) {
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            int a = nums[i][i], b = nums[i][nums.size() - i - 1];
            if (is_prime(a)) {
                ans = std::max(ans, a);
            }
            if (is_prime(b)) {
                ans = std::max(ans, b);
            }
        }

        return ans;
    }
};