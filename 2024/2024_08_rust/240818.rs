// 264. Ugly Number II
// Medium
// https://leetcode.com/problems/ugly-number-ii/

// Idea designed by official solution

use std::cmp::min;

struct Solution;

impl Solution {
    pub fn nth_ugly_number(n: i32) -> i32 {
        let n = n as usize;
        let mut ugly_arr = vec![1];
        let mut mult_2_idx = 0;
        let mut mult_3_idx = 0;
        let mut mult_5_idx = 0;

        for _ in 1..n {
            let mult_2_next = ugly_arr[mult_2_idx] * 2;
            let mult_3_next = ugly_arr[mult_3_idx] * 3;
            let mult_5_next = ugly_arr[mult_5_idx] * 5;
            let next_ugly_num = min(mult_2_next, min(mult_3_next, mult_5_next));

            ugly_arr.push(next_ugly_num);
            // There might be mult_x_next == mult_y_next
            if next_ugly_num == mult_2_next {
                mult_2_idx += 1;
            }
            if next_ugly_num == mult_3_next {
                mult_3_idx += 1;
            }
            if next_ugly_num == mult_5_next {
                mult_5_idx += 1;
            }
        }

        ugly_arr[n as usize - 1]
    }
}

fn main() {
    let x = 10;
    let ans = Solution::nth_ugly_number(x);
    println!("ans of {x} = {ans}")
}
