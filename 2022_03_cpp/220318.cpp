//
// Created by z on 3/18/2022.
// # 316
// ( 体验极差，想了好久，复杂度还很高 )
class Solution {
public:

    string removeDuplicateLetters(string s) {

        string ret;
        int cbrm[10001]; // can be removed
        for (int i = 0; i <= s.size(); i++) cbrm[i] = 0;
        unordered_map<char, int> m;
        unordered_map<char, int> hvc; // have been chosen

        for (int i = 1; i <= s.size(); i++)
        {
            int index = s.size() - i;
            if (m.find(s[index]) != m.end())
                cbrm[index] = 1;
            else
            {
                m[s[index]] = 1;
                cbrm[index] = 0;
            }
        }

        int head = 0;
        while (head < s.size())
        {
            int ch_idx = head;
            if (cbrm[head] == 0)
            {
                if (hvc.find(s[head]) == hvc.end())
                {
                    ret += s[head];
                    hvc[s[head]] = 1;
                }
                head++;
                continue;
            }

            int ch_char = s[head];
            for (int i = head+1; i < s.size() && (cbrm[i-1] == 1 || hvc.find(s[i-1]) != hvc.end()); i++)
            {
                if ((ch_char > s[i]) && (hvc.find(s[i]) == hvc.end()))
                {
                    ch_char = s[i];
                    ch_idx  = i;
                }
            }

            if (hvc.find(ch_char) == hvc.end())
            {
                ret += ch_char;
                hvc[ch_char] = 1;
            }

            head = ch_idx + 1;

        }
        return ret;
    }
};