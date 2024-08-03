use std::collections::HashMap;

struct Solution;

impl Solution {
    pub fn can_be_equal(target: Vec<i32>, arr: Vec<i32>) -> bool {
        let mut m = HashMap::<i32, i32>::new();

        for num in target.into_iter() {
            m.insert(
                num,
                match m.get(&num) {
                    None => 1,
                    Some(times) => times + 1,
                },
            );
        }

        for num in arr.into_iter() {
            match m.get(&num) {
                None => return false,
                Some(times) => {
                    if *times == 1 {
                        m.remove(&num);
                    } else {
                        m.insert(num, *times - 1);
                    }
                }
            }
        }
        true
    }
}

fn main() {}
