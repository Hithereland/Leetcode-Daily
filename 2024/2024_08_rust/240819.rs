// 650. 2 Keys Keyboard
// Medium
// https://leetcode.com/problems/2-keys-keyboard/

use std::cmp::min;

struct Solution;

impl Solution {
    pub fn min_steps(n: i32) -> i32 {
        let n = n as usize;
        let mut dp = vec![vec![-1; n + 1]; n + 1];

        dp[1][0] = 0;
        dp[1][1] = 1;

        for i in 2..n + 1 {
            for paste in 1..i {
                if dp[(i - paste) as usize][paste] == -1 {
                    continue;
                }
                dp[i][paste] = dp[(i - paste) as usize][paste] + 1;
            }
            dp[i][i] = dp[i]
                .iter()
                .filter(|&&x| x != -1)
                .fold(1005, |acc, &x| min(acc, x))
                + 1
        }

        dp[n]
            .iter()
            .filter(|&&x| x != -1)
            .fold(1005, |acc, &x| min(acc, x))
    }
}

fn main() {
    let x = 18;
    let ans = Solution::min_steps(x);
    println!("ans of {x} is {ans}");
}
