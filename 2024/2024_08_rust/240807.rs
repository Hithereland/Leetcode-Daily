// 273. Integer to English Words
// Hard
// https://leetcode.com/problems/integer-to-english-words/

// Elegantly designed code from Minamikaze392

struct Solution;

impl Solution {
    pub fn number_to_words(mut num: i32) -> String {
        if num == 0 {
            return "Zero".to_string();
        }
        let mapping = [
            (90, "Ninety"),
            (80, "Eighty"),
            (70, "Seventy"),
            (60, "Sixty"),
            (50, "Fifty"),
            (40, "Forty"),
            (30, "Thirty"),
            (20, "Twenty"),
            (19, "Nineteen"),
            (18, "Eighteen"),
            (17, "Seventeen"),
            (16, "Sixteen"),
            (15, "Fifteen"),
            (14, "Fourteen"),
            (13, "Thirteen"),
            (12, "Twelve"),
            (11, "Eleven"),
            (10, "Ten"),
            (9, "Nine"),
            (8, "Eight"),
            (7, "Seven"),
            (6, "Six"),
            (5, "Five"),
            (4, "Four"),
            (3, "Three"),
            (2, "Two"),
            (1, "One"),
        ];
        let units = [
            (1_000_000_000, "Billion"),
            (1_000_000, "Million"),
            (1_000, "Thousand"),
        ];

        let mut v = Vec::<&str>::new();
        for &(x, s) in units.iter() {
            let quot = num / x;
            if quot != 0 {
                Self::pick_words(quot, &mapping, &mut v);
                v.push(s);
                num %= x;
            }
        }
        Self::pick_words(num, &mapping, &mut v);
        v.join(" ")
    }

    fn pick_words<'a>(mut val: i32, mapping: &[(i32, &'a str)], v: &mut Vec<&'a str>) {
        if val >= 100 {
            Self::pick_words(val / 100, mapping, v);
            v.push("Hundred");
            val %= 100;
        }
        for &(x, s) in mapping.iter() {
            if val >= x {
                v.push(s);
                val -= x;
            }
        }
    }
}

fn main() {
    println!("{}", Solution::number_to_words(114514))
}
