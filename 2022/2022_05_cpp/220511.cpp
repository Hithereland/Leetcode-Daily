//
// Created by z on 5/13/2022.
// # 1641
// I am too stupid to come up with this idea.

class Solution {
public:
    int countVowelStrings(int n) {

        int a, e, i, o, u;
        a = e = i = o = u = 1;

        while (n--) {

            a += e + i + o + u;
            e += i + o + u;
            i += o + u;
            o += u;
        }

        return a;
    }
};

