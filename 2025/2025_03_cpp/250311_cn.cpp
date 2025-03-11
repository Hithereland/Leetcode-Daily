// 2012. 数组美丽值求和
// Medium
// https://leetcode.cn/problems/sum-of-beauty-in-the-array/

#include <functional>
#include <iostream>
#include <iterator>
#include <queue>
#include <vector>

class Solution
{
public:
    int sumOfBeauties(std::vector<int> &nums) {

        int ans = 0;
        // judge 1 and 0
        for (int i = 1; i < nums.size() - 1; i++) {
            if (nums[i - 1] < nums[i] && nums[i] < nums[i + 1]) {
                ans += 1;
            }
        }

        // judge 2
        auto left = std::priority_queue<int, std::vector<int>, std::less<>>();
        auto right = std::priority_queue<int, std::vector<int>, std::greater<>>();
        auto topop_cache = std::priority_queue<int, std::vector<int>, std::less<>>();

        // init
        for (int i = 0; i < nums.size() - 2; i++) {
            // should not contain nums[n-2]
            left.push(nums[i]);
        }
        right.push(nums[nums.size() - 1]);

        for (int i = nums.size() - 2; i > 0; i--) {
            if (left.top() < nums[i] && nums[i] < right.top()) {
                ans += 1;
            }
            right.push(nums[i]);
            int topop = nums[i - 1];
            topop_cache.push(topop);
            while (!topop_cache.empty() && topop_cache.top() >= left.top()) {
                left.pop();
                topop_cache.pop();
            }
        }

        return ans;
    }
};

int main() {
    auto solution = Solution();
    std::vector<int> arr = {1, 2, 3};
    solution.sumOfBeauties(arr);
}