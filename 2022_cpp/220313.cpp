//
// Created by z on 3/13/2022.
//

class Solution {
public:
    bool isValid(string s) {

        unordered_map <char, int> m;
        int idx = 0;
        for (auto c : "([{}])") {
            m[c] = idx++;
        }

        stack<char> st;
        for (auto c : s) {
            if (m[c] <= 2)
                st.push(c);
            else if (st.size() != 0 && m[c] + m[st.top()] == 5)
                st.pop();
            else
                return false;
        }

        if (st.size() == 0)
            return true;
        else
            return false;
    }
};
