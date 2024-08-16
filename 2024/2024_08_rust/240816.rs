// 624. Maximum Distance in Arrays
// Medium
// https://leetcode.com/problems/maximum-distance-in-arrays/

struct Solution;

impl Solution {
    pub fn max_distance(arrays: Vec<Vec<i32>>) -> i32 {
        let mut min_record = *arrays[0].first().unwrap();
        let mut max_record = *arrays[0].last().unwrap();
        let mut ret = 0;

        for i in 1..arrays.len() {
            let arr = &arrays[i];
            let &min_tmp = arr.first().unwrap();
            let &max_tmp = arr.last().unwrap();
            let tmp_ans = std::cmp::max((max_record - min_tmp).abs(), (min_record - max_tmp).abs());
            ret = std::cmp::max(tmp_ans, ret);

            min_record = std::cmp::min(min_record, min_tmp);
            max_record = std::cmp::max(max_record, max_tmp);
        }
        ret
    }
}

fn main() {}
