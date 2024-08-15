// 860. Lemonade Change
// Easy
// https://leetcode.com/problems/lemonade-change/

use std::collections::HashMap;

struct Solution;

impl Solution {
    pub fn lemonade_change(bills: Vec<i32>) -> bool {
        let denominations = vec![20, 10, 5];
        let mut map = denominations
            .iter()
            .map(|&x| (x, 0))
            .collect::<HashMap<_, _>>();

        for &b in bills.iter() {
            let mut change = b - 5;
            for &deno in denominations.iter() {
                while deno <= change && map[&deno] > 0 {
                    change -= deno;
                    *map.get_mut(&deno).unwrap() -= 1;
                }
            }

            if change > 0 {
                return false;
            }

            *map.get_mut(&b).unwrap() += 1;
        }

        true
    }
}

fn main() {}
