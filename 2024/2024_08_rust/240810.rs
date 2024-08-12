// 959. Regions Cut By Slashes
// Medium
// https://leetcode.com/problems/regions-cut-by-slashes/

use std::collections::{HashMap, HashSet};

struct Solution;

impl Solution {
    fn transform_grid(grid: Vec<String>) -> (Vec<Vec<bool>>, usize) {
        let mut ret_grid = Vec::new();
        let n = grid.len();

        let space_matrix = vec![
            vec![false, false, false],
            vec![false, false, false],
            vec![false, false, false],
        ];
        let slash_matrix = vec![
            vec![false, false, true],
            vec![false, true, false],
            vec![true, false, false],
        ];
        let backslash_matrix = vec![
            vec![true, false, false],
            vec![false, true, false],
            vec![false, false, true],
        ];

        for r in 0..n {
            let mut new_row = vec![vec![], vec![], vec![]];

            for c in 0..n {
                match grid[r].as_bytes()[c] as char {
                    ' ' => {
                        for i in 0..3 {
                            new_row[i].extend(space_matrix[i].clone());
                        }
                    }
                    '\\' => {
                        for i in 0..3 {
                            new_row[i].extend(backslash_matrix[i].clone());
                        }
                    }
                    '/' => {
                        for i in 0..3 {
                            new_row[i].extend(slash_matrix[i].clone());
                        }
                    }
                    _ => {
                        // never reach
                    }
                }
            }

            ret_grid.extend(new_row);
        }

        (ret_grid, n * 3)
    }

    pub fn regions_by_slashes(grid: Vec<String>) -> i32 {
        let (grid, n) = Solution::transform_grid(grid);

        let mut union_set = (0..n * n).collect::<Vec<usize>>();
        fn union_find(union_set: &mut Vec<usize>, a: usize) -> usize {
            if union_set[a] == a {
                a
            } else {
                union_set[a] = union_find(union_set, union_set[a]);
                union_set[a]
            }
        }

        let mut union_merge = |a, b| {
            let roota = union_find(&mut union_set, a);
            union_set[roota] = union_find(&mut union_set, b);
        };

        let dr: Vec<i32> = vec![0, 0, 1, -1];
        let dc: Vec<i32> = vec![1, -1, 0, 0];
        for r in 0..n {
            for c in 0..n {
                if grid[r][c] {
                    continue;
                }
                let union_id = r * n + c;
                for i in 0..4 {
                    let (nr, nc) = (dr[i] + r as i32, dc[i] + c as i32);
                    if nr < 0 || nr >= n as i32 || nc < 0 || nc >= n as i32 {
                        continue;
                    }
                    let nr = nr as usize;
                    let nc = nc as usize;
                    if grid[nr][nc] {
                        // is blocked
                        continue;
                    }
                    let next_union_id = nr * n + nc;
                    union_merge(union_id, next_union_id);
                }
            }
        }

        (0..n * n)
            .filter(|x| !grid[x / n][x % n])
            .map(|x| union_find(&mut union_set, x))
            .collect::<HashSet<usize>>()
            .len() as i32
    }
}

/*
== CHATGPT VERSION
*/

struct Solution_CHATGPT;

impl Solution_CHATGPT {
    fn transform_grid(grid: Vec<String>) -> (Vec<Vec<bool>>, usize) {
        let n = grid.len();
        let matrices = vec![
            (' ', vec![vec![false; 3]; 3]),
            (
                '/',
                vec![
                    vec![false, false, true],
                    vec![false, true, false],
                    vec![true, false, false],
                ],
            ),
            (
                '\\',
                vec![
                    vec![true, false, false],
                    vec![false, true, false],
                    vec![false, false, true],
                ],
            ),
        ]
        .into_iter()
        .collect::<HashMap<_, _>>();

        let ret_grid = grid
            .iter()
            .map(|row| {
                let mut new_rows = vec![vec![], vec![], vec![]];
                for &ch in row.as_bytes() {
                    let matrix = &matrices[&(ch as char)];
                    for i in 0..3 {
                        new_rows[i].extend_from_slice(&matrix[i]);
                    }
                }
                new_rows
            })
            .flatten()
            .collect();

        (ret_grid, n * 3)
    }

    pub fn regions_by_slashes(grid: Vec<String>) -> i32 {
        let (grid, n) = Self::transform_grid(grid);
        let mut union_set: Vec<_> = (0..n * n).collect();

        fn union_find(union_set: &mut Vec<usize>, mut a: usize) -> usize {
            while union_set[a] != a {
                union_set[a] = union_set[union_set[a]];
                a = union_set[a];
            }
            a
        }

        let mut union_merge = |a, b| {
            let root_a = union_find(&mut union_set, a);
            let root_b = union_find(&mut union_set, b);
            union_set[root_a] = root_b;
        };

        const DR: [i32; 4] = [0, 0, 1, -1];
        const DC: [i32; 4] = [1, -1, 0, 0];

        for r in 0..n {
            for c in 0..n {
                if !grid[r][c] {
                    let union_id = r * n + c;
                    for i in 0..4 {
                        let (nr, nc) = (r as i32 + DR[i], c as i32 + DC[i]);
                        if (0..n as i32).contains(&nr)
                            && (0..n as i32).contains(&nc)
                            && !grid[nr as usize][nc as usize]
                        {
                            union_merge(union_id, nr as usize * n + nc as usize);
                        }
                    }
                }
            }
        }

        (0..n * n)
            .filter(|&x| !grid[x / n][x % n])
            .map(|x| union_find(&mut union_set, x))
            .collect::<HashSet<_>>()
            .len() as i32
    }
}

fn main() {
    let ans = Solution::regions_by_slashes(vec!["/\\".to_string(), "\\/".to_string()]);
    println!("ans = {ans}");
}
