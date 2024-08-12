// 703. Kth Largest Element in a Stream
// Easy
// https://leetcode.com/problems/kth-largest-element-in-a-stream/

struct KthLargest {
    sorted_arr: Vec<i32>,
    k: i32,
}

/**
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl KthLargest {
    fn new(k: i32, nums: Vec<i32>) -> Self {
        let mut nums = nums;
        nums.sort();
        KthLargest {
            sorted_arr: nums,
            k: k,
        }
    }

    fn add(&mut self, val: i32) -> i32 {
        match self.sorted_arr.binary_search(x) {
            Ok(i) => self.sorted_arr.insert(i, x),
            Err(i) => self.sorted_arr.insert(i, x),
        }
        self.sorted_arr[self.sorted_arr.len() - k as usize]
    }
}

/**
 * Your KthLargest object will be instantiated and called as such:
 * let obj = KthLargest::new(k, nums);
 * let ret_1: i32 = obj.add(val);
 */

fn main() {}
