// 1568. Minimum Number of Days to Disconnect Island
// Hard
// https://leetcode.com/problems/minimum-number-of-days-to-disconnect-island/

// Elegantly designed code from kartikdevsharmaa
// https://leetcode.com/problems/minimum-number-of-days-to-disconnect-island/discuss/5612177/
// Tarjan Algorithm

struct Solution;

impl Solution {
    pub fn min_days(grid: Vec<Vec<i32>>) -> i32 {
        let (rows, cols) = (grid.len(), grid[0].len());
        let mut discovery_time = vec![vec![0; cols]; rows];
        let mut lowest_reachable_time = vec![vec![0; cols]; rows];
        let mut time = 1;
        let mut has_articulation_point = false;
        let mut total_land_cells = 0;
        let directions = [(0, 1), (1, 0), (0, -1), (-1, 0)];

        fn is_valid_cell(row: i32, col: i32, grid: &Vec<Vec<i32>>) -> bool {
            row >= 0
                && col >= 0
                && (row as usize) < grid.len()
                && (col as usize) < grid[0].len()
                && grid[row as usize][col as usize] == 1
        }

        fn dfs(
            row: i32,
            col: i32,
            parent_row: i32,
            parent_col: i32,
            grid: &Vec<Vec<i32>>,
            discovery_time: &mut Vec<Vec<i32>>,
            lowest_reachable_time: &mut Vec<Vec<i32>>,
            time: &mut i32,
            has_articulation_point: &mut bool,
            total_land_cells: &mut i32,
        ) {
            discovery_time[row as usize][col as usize] = *time;
            lowest_reachable_time[row as usize][col as usize] = *time;
            *time += 1;
            *total_land_cells += 1;
            let mut children = 0;

            for &(dr, dc) in &[(0, 1), (1, 0), (0, -1), (-1, 0)] {
                let new_row = row + dr;
                let new_col = col + dc;

                if !is_valid_cell(new_row, new_col, grid) {
                    continue;
                }

                if discovery_time[new_row as usize][new_col as usize] == 0 {
                    children += 1;
                    dfs(
                        new_row,
                        new_col,
                        row,
                        col,
                        grid,
                        discovery_time,
                        lowest_reachable_time,
                        time,
                        has_articulation_point,
                        total_land_cells,
                    );
                    lowest_reachable_time[row as usize][col as usize] = lowest_reachable_time
                        [row as usize][col as usize]
                        .min(lowest_reachable_time[new_row as usize][new_col as usize]);

                    if lowest_reachable_time[new_row as usize][new_col as usize]
                        >= discovery_time[row as usize][col as usize]
                        && parent_row != -1
                    {
                        *has_articulation_point = true;
                    }
                } else if (new_row != parent_row || new_col != parent_col)
                    && discovery_time[new_row as usize][new_col as usize]
                        < discovery_time[row as usize][col as usize]
                {
                    lowest_reachable_time[row as usize][col as usize] = lowest_reachable_time
                        [row as usize][col as usize]
                        .min(discovery_time[new_row as usize][new_col as usize]);
                }
            }

            if parent_row == -1 && children > 1 {
                *has_articulation_point = true;
            }
        }

        let mut islands = 0;
        for row in 0..rows {
            for col in 0..cols {
                if grid[row][col] == 1 && discovery_time[row][col] == 0 {
                    islands += 1;
                    if islands > 1 {
                        return 0; // More than one island
                    }
                    dfs(
                        row as i32,
                        col as i32,
                        -1,
                        -1,
                        &grid,
                        &mut discovery_time,
                        &mut lowest_reachable_time,
                        &mut time,
                        &mut has_articulation_point,
                        &mut total_land_cells,
                    );
                }
            }
        }

        if total_land_cells == 0 {
            return 0; // No land
        }
        if total_land_cells == 1 {
            return 1; // Only one land cell
        }
        if islands == 0 {
            return 0; // No islands (should not happen if input is valid)
        }
        if has_articulation_point {
            1
        } else {
            2
        }
    }
}

fn main() {}
