// 1508. Range Sum of Sorted Subarray Sums
// Medium
// https://leetcode.com/problems/range-sum-of-sorted-subarray-sums/

struct Solution;

impl Solution {
    pub fn range_sum(nums: Vec<i32>, n: i32, left: i32, right: i32) -> i32 {
        let mut prefix_sum = nums;
        let left = (left - 1) as usize;
        let right = (right - 1) as usize;
        const M: i32 = 1000000007;
        let n = n as usize;

        for i in 1..n {
            prefix_sum[i] += prefix_sum[i - 1];
        }

        let mut subarr_sums = Vec::new();
        for st in 0..n {
            for ed in st..n {
                subarr_sums.push(prefix_sum[ed] - if st == 0 { 0 } else { prefix_sum[st - 1] });
            }
        }

        let mut ret = 0;

        subarr_sums.sort();
        for i in 0..subarr_sums.len() {
            if i >= left && i <= right {
                ret += subarr_sums[i];
                ret %= M;
            }
        }
        ret
    }
}

fn main() {}
