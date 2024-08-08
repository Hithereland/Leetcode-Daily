// 885. Spiral Matrix III
// Medium
// https://leetcode.com/problems/spiral-matrix-iii/

struct Solution;

impl Solution {
    pub fn spiral_matrix_iii(rows: i32, cols: i32, r_start: i32, c_start: i32) -> Vec<Vec<i32>> {
        let mut cell_cnt = (rows * cols) as usize;
        // right, down, left, up
        let dr = vec![0, 1, 0, -1];
        let dc = vec![1, 0, -1, 0];

        let mut ret = Vec::new();
        let (mut r_tmp, mut c_tmp) = (r_start, c_start);
        ret.push(vec![r_tmp, c_tmp]);
        cell_cnt -= 1;

        for i in 0..usize::max_value() {
            if cell_cnt == 0 {
                break;
            }
            let steps = i / 2 + 1;
            let drct = i % 4;
            for _ in 0..steps {
                if cell_cnt == 0 {
                    break;
                }
                r_tmp += dr[drct];
                c_tmp += dc[drct];
                if 0 <= r_tmp && r_tmp < rows && 0 <= c_tmp && c_tmp < cols {
                    ret.push(vec![r_tmp, c_tmp]);
                    cell_cnt -= 1;
                }
            }
        }

        ret
    }
}

fn main() {}
