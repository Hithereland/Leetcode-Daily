// 1937. Maximum Number of Points with Cost
// Medium
// https://leetcode.com/problems/maximum-number-of-points-with-cost/

use std::cmp::max;
struct Solution;

impl Solution {
    pub fn max_points(points: Vec<Vec<i32>>) -> i64 {
        if points.len() == 1 {
            return points[0].iter().fold(0, |ans, &x| max(ans, x as i64));
        } else {
        }

        let cols = points[0].len();
        let mut dp: Vec<Vec<i64>> = vec![vec![0; cols]; 2];

        for r in 0..points.len() {
            let dp_prev = &dp[(r + 1) % 2];
            let mut dp_curr = vec![0; cols];
            let points = &points[r];

            let mut left_best = vec![0; cols];
            let mut right_best = vec![0; cols];

            left_best[0] = dp_prev[0];
            dp_curr[0] = left_best[0] + points[0] as i64;
            for i in 1..cols {
                left_best[i] = max(left_best[i - 1] - 1, dp_prev[i]);
                dp_curr[i] = left_best[i] + points[i] as i64;
            }

            right_best[cols - 1] = dp_prev[cols - 1];
            dp_curr[cols - 1] = max(
                dp_curr[cols - 1],
                right_best[cols - 1] + points[cols - 1] as i64,
            );
            for i in 1..cols {
                let i = cols - 1 - i;
                right_best[i] = max(right_best[i + 1] - 1, dp_prev[i]);
                dp_curr[i] = max(dp_curr[i], right_best[i] + points[i] as i64);
            }

            dp[r % 2] = dp_curr;
        }

        let ret = &dp[(points.len() + 1) % 2];
        ret.iter().fold(0, |ans, &x| max(ans, x as i64))
    }
}

fn main() {
    let test = vec![vec![1, 2, 3], vec![1, 5, 1], vec![3, 1, 1]];
    Solution::max_points(test);
}
