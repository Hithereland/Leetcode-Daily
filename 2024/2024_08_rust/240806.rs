// 3016. Minimum Number of Pushes to Type Word II
// Medium
// https://leetcode.com/problems/minimum-number-of-pushes-to-type-word-ii/

use std::collections::HashMap;

struct Solution;

impl Solution {
    pub fn minimum_pushes(word: String) -> i32 {
        let mut arr: Vec<(u8, i32)> = word
            .into_bytes()
            .into_iter()
            .fold(HashMap::new(), |mut acc, ch| {
                *acc.entry(ch).or_insert(0) += 1;
                acc
            })
            .into_iter()
            .collect();
        arr.sort_by(|a, b| b.1.cmp(&a.1));

        let mut ret = 0;
        for i in 0..arr.len() {
            ret += (i / 8 + 1) as i32 * arr.get(i).unwrap().1;
        }

        ret
    }
}

fn main() {}
