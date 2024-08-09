// 840. Magic Squares In Grid
// Medium
// https://leetcode.com/problems/magic-squares-in-grid/

struct Solution;

impl Solution {
    pub fn num_magic_squares_inside(grid: Vec<Vec<i32>>) -> i32 {
        let (row, col) = (grid.len(), grid[0].len());
        if row < 3 || col < 3 {
            return 0;
        }

        let mut ret = 0;

        let mut num_counter: Vec<_> = (0..10).map(|_| 0).collect();
        for r in 0..(row - 2) {
            for c in 0..(col - 2) {
                let mut valid = true;
                for x in num_counter.iter_mut() {
                    *x = 0;
                }
                // nums are in [1..9] and distinct
                for i in 0..3 {
                    for j in 0..3 {
                        let &val = &(grid[r + i][c + j] as usize);
                        if val > 9 || val < 1 {
                            valid = false;
                            break;
                        }
                        if num_counter[val] == 1 {
                            valid = false;
                            break;
                        }
                        num_counter[val] = 1;
                    }
                }

                // each row, column, and both diagonals all have the same sum
                // sum of rows
                for i in 0..3 {
                    let mut row_sum = 0;
                    for j in 0..3 {
                        row_sum += grid[r + i][c + j];
                    }
                    if row_sum != 15 {
                        valid = false;
                        break;
                    }
                }
                // sum of cols
                for i in 0..3 {
                    let mut row_sum = 0;
                    for j in 0..3 {
                        row_sum += grid[r + j][c + i];
                    }
                    if row_sum != 15 {
                        valid = false;
                        break;
                    }
                }
                // sum of diagonals
                if grid[r][c] + grid[r + 1][c + 1] + grid[r + 2][c + 2] != 15 {
                    valid = false;
                }
                if grid[r + 2][c] + grid[r + 1][c + 1] + grid[r][c + 2] != 15 {
                    valid = false;
                }

                if valid {
                    ret += 1;
                }
            }
        }
        ret
    }
}

fn main() {}
