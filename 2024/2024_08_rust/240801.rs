// 2678. Number of Senior Citizens
// Easy
// https://leetcode.com/problems/number-of-senior-citizens/submissions/

struct Solution;

impl Solution {
    pub fn count_seniors(details: Vec<String>) -> i32 {
        details
            .into_iter()
            .map(|s| s[11..12].parse::<i32>().unwrap())
            .filter(|age| *age > 60)
            .count() as i32
    }
}

fn main() {
    println!("Hello, world!");
}
