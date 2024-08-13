// 40. Combination Sum II
// Medium
// https://leetcode.com/problems/combination-sum-ii/

struct Solution;

impl Solution {
    fn combination_sum_slice(arr: &[i32], target: i32) -> Vec<Vec<i32>> {
        let mut ret = Vec::new();
        if arr.len() == 0 {
            return ret;
        }

        let first = arr[0];
        if target < first {
            return ret;
        }

        if target == first {
            ret.push(vec![first]);
        } else {
            let with_first_subs = Solution::combination_sum_slice(&arr[1..], target - first);
            for mut sub in with_first_subs.into_iter() {
                sub.insert(0, first);
                ret.push(sub);
            }
        }

        // Should find a different next
        for i in 1..arr.len() {
            if arr[i] != first {
                for without_first in Solution::combination_sum_slice(&arr[i..], target).into_iter()
                {
                    ret.push(without_first);
                }
                break;
            }
        }

        ret
    }

    pub fn combination_sum2(candidates: Vec<i32>, target: i32) -> Vec<Vec<i32>> {
        let mut arr = candidates;
        arr.sort();
        Solution::combination_sum_slice(&arr, target)
    }
}

fn main() {}
