// 2134. Minimum Swaps to Group All 1's Together II
// Medium
// https://leetcode.com/problems/minimum-swaps-to-group-all-1s-together-ii/

struct Solution;

impl Solution {
    pub fn min_swaps(nums: Vec<i32>) -> i32 {
        let window_width = nums.iter().sum::<i32>() as usize;
        let n = nums.len();
        let mut zeros = window_width as i32 - nums[0..window_width].iter().sum::<i32>();
        let mut min_zeros = zeros;

        for i in 1..n {
            let remove_one = nums[i - 1];
            let add_one = nums[(i + window_width - 1) % n];
            zeros = zeros + remove_one - add_one;
            min_zeros = std::cmp::min(zeros, min_zeros);
        }
        min_zeros
    }
}

fn main() {
    println!["{}", Solution::min_swaps(vec![0, 1, 1, 1, 0, 0, 1, 1, 0])];
}
