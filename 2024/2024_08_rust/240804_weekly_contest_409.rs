use std::collections::HashMap;

struct SolutionA;

struct neighborSum {
    grid: Vec<Vec<i32>>,
    m: HashMap<i32, (i32, i32)>,
    n: usize,
}

/**
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl neighborSum {
    fn new(grid: Vec<Vec<i32>>) -> Self {
        let mut m = HashMap::new();
        let n = grid.len();
        for r in 0..n {
            for c in 0..n {
                m.insert(grid[r][c], (r as i32, c as i32));
            }
        }
        neighborSum {
            grid: grid,
            m: m,
            n: n,
        }
    }

    fn adjacent_sum(&self, value: i32) -> i32 {
        let dr = vec![1, -1, 0, 0];
        let dc = vec![0, 0, 1, -1];
        let (r, c) = self.m.get(&value).unwrap();
        let n = self.n as i32;
        let mut ret = 0;
        for i in 0..4 {
            let nr = dr[i] + r;
            let nc = dc[i] + c;
            if nr < 0 || nr > n - 1 || nc < 0 || nc > n - 1 {
                continue;
            }
            ret += self.grid[nr as usize][nc as usize];
        }
        ret
    }

    fn diagonal_sum(&self, value: i32) -> i32 {
        let dr = vec![1, -1, 1, -1];
        let dc = vec![1, 1, -1, -1];
        let (r, c) = self.m.get(&value).unwrap();
        let n = self.n as i32;
        let mut ret = 0;
        for i in 0..4 {
            let nr = dr[i] + r;
            let nc = dc[i] + c;
            if nr < 0 || nr > n - 1 || nc < 0 || nc > n - 1 {
                continue;
            }
            ret += self.grid[nr as usize][nc as usize];
        }
        ret
    }
}

/**
 * Your neighborSum object will be instantiated and called as such:
 * let obj = neighborSum::new(grid);
 * let ret_1: i32 = obj.adjacent_sum(value);
 * let ret_2: i32 = obj.diagonal_sum(value);
 */

struct Solution_B;

impl Solution_B {
    pub fn shortest_distance_after_queries(n: i32, queries: Vec<Vec<i32>>) -> Vec<i32> {
        let mut shortest = Vec::new();
        let mut ret = Vec::new();
        let n = n as usize;
        for st in 0..n {
            let mut from_st = Vec::new();
            for ed in 0..n {
                from_st.push(if ed < st { 502 } else { (ed - st) as i32 });
            }
            shortest.push(from_st);
        }

        for q in queries.iter() {
            let l = q[0] as usize;
            let r = q[1] as usize;
            for st in 0..n {
                if st >= r {
                    break;
                }
                for ed in st..n {
                    if ed <= l {
                        continue;
                    }
                    let use_new_path = shortest[st][l] + 1 + shortest[r][ed];
                    shortest[st][ed] = std::cmp::min(shortest[st][ed], use_new_path);
                }
            }
            ret.push(shortest[0][n - 1]);
        }

        ret
    }
}

struct Solution_C;

impl Solution_C {
    pub fn shortest_distance_after_queries(n: i32, queries: Vec<Vec<i32>>) -> Vec<i32> {
        let mut ret = Vec::new();
        let mut tmp_ans = n - 1;

        let mut path = Vec::new();
        // init path
        for i in 0..n - 1 {
            path.push((i + 1) as usize);
        }

        for q in queries.iter() {
            // do deletion
            let left = q[0] as usize;
            let right = q[1] as usize;
            let mut deletions = 0;
            let mut it = path[left];
            path[left] = right;
            while it < right {
                let next_it = path[it];
                path[it] = right;
                deletions += 1;
                it = next_it;
            }

            tmp_ans -= deletions;
            ret.push(tmp_ans);
        }

        ret
    }
}

fn main() {}
