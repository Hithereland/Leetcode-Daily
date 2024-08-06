// 2053. Kth Distinct String in an Array
// Easy
// https://leetcode.com/problems/kth-distinct-string-in-an-array/

use std::collections::HashMap;

struct Solution;

impl Solution {
    pub fn kth_distinct(arr: Vec<String>, k: i32) -> String {
        let mut k = k as usize;
        let mut map: HashMap<_, _> = arr.iter().fold(HashMap::new(), |mut acc, s| {
            *acc.entry(s).or_insert(0) += 1;
            acc
        });

        let mut ret = "".to_string();
        for s in arr.iter() {
            match map.get_mut(&s) {
                Some(1) => {
                    map.insert(s, 0);
                    k -= 1;
                }
                Some(_) => {}
                None => {}
            }
            if k == 0 {
                ret = s.clone();
                break;
            }
        }

        return ret;
    }
}

fn main() {}
