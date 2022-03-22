//
// Created by z on 3/15/2022.
// # 1249

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> st;
        unordered_map<int, int> m_del;
        int lmr = 0; // left minus right
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                lmr++;
                st.push(i);
            }
            else if (s[i] == ')') {
                lmr--;
                if (lmr < 0) {
                    lmr = 0;
                    m_del[i] = 1;
                }
                else {
                    st.pop();
                }
            }
            else continue;
        }

        while (st.size() != 0) {
            m_del[st.top()] = 1;
            st.pop();
        }

        string ret;
        for (int i = 0; i < s.size(); i++) {
            if (m_del.find(i) == m_del.end()) {
                ret += s[i];
            }
        }

        return ret;
    }
};