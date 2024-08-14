// 719. Find K-th Smallest Pair Distance
// Hard
// https://leetcode.com/problems/find-k-th-smallest-pair-distance/

// Idea inspired by Rococo99

struct Solution;

impl Solution {
    // less or equal
    fn leq_distance_pairs(nums: &[i32], d: i32) -> i32 {
        let mut left = 0;
        let mut ret = 0;

        for right in 1..nums.len() {
            while nums[right] - nums[left] > d {
                left += 1;
            }
            ret += (right - left) as i32
        }

        ret
    }

    pub fn smallest_distance_pair(nums: Vec<i32>, k: i32) -> i32 {
        let mut nums = nums;
        nums.sort();
        // binary search
        let mut l = 0;
        let mut r = nums[nums.len() - 1] - nums[0];
        let mut m = (l + r) / 2;

        while l < r {
            if Solution::leq_distance_pairs(&nums, m) < k {
                l = m + 1;
            } else {
                r = m;
            }
            m = (l + r) / 2;
            if l == r {
                break;
            }
        }
        r
    }
}

fn main() {}
