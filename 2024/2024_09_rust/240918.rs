// 179. Largest Number
// Medium
// https://leetcode.com/problems/largest-number

struct Solution;
struct Solution_Clean;

impl Solution {

    pub fn str_from(item: i32) -> String {
        if item == 0 {
            return "0".to_string();
        }
        let mut item = item as u32;
        let mut u8_v = vec![];
        while item != 0 {
            let head = ((item % 10) + 48) as u8;
            u8_v.insert(0, head);
            item /= 10;
        }
        String::from_utf8(u8_v).unwrap()
    }

    pub fn largest_number(nums: Vec<i32>) -> String {
        let mut num_strs: Vec<String> = nums.iter().map(|&x| Self::str_from(x)).collect();
        num_strs.sort_by(|a, b| { (a.to_owned() + b.as_str()).cmp(&(b.to_owned() + a.as_str())) });
        num_strs.reverse();
        let ret = num_strs.join("");
        if let Some(48) = ret.clone().into_bytes().get(0) {
            return "0".to_string();
        }
        ret
    }
}

impl Solution_Clean {
    // TvT
    pub fn largest_number(nums: Vec<i32>) -> String {
        let mut num_strs: Vec<String> = nums.iter().map(|&x| x.to_string()).collect();
        num_strs.sort_by(|a, b| (b.clone() + a).cmp(&(a.clone() + b)));
        
        let ret = num_strs.join("");
        if ret.starts_with('0') {
            "0".to_string()
        } else {
            ret
        }
    }
}


fn main() {
    println!("{}", Solution::largest_number(vec![0, 0]))
}