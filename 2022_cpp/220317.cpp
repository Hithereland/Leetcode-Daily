//
// Created by z on 3/17/2022.
// # 856

class Solution {
public:
    int getType(string s) {
        int depth = 0;
        for (int i = 0; i < s.size() - 1; i++) {
            if (s[i] == '(')
                depth++;
            else
                depth--;
            if (depth == 0)
                return i;
        }
        return -1;
    }


    int scoreOfParentheses(string s) {
        if (s.size() == 2)
            return 1;
        int type = getType(s);
        if (type == -1)
            return 2 * scoreOfParentheses(s.substr(1,s.size()-2));
        else
            return scoreOfParentheses(s.substr(0,type+1)) +
                   scoreOfParentheses(s.substr(type+1));
    }
};