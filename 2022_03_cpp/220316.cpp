//
// Created by z on 3/16/2022.
// # 946

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;

        int ji = 0, pi = 0; // judge index, push index
        while (ji < popped.size()) {
            if (st.size() == 0) {
                if (pi < pushed.size())
                    st.push(pushed[pi]);
                else
                    return false;
                pi++;
            }
            if (popped[ji] != st.top()) {
                if (pi < pushed.size())
                    st.push(pushed[pi]);
                else
                    return false;
                pi++;
            }
            else {
                ji++;
                st.pop();
            }
        }

        if (st.size() == 0)
            return true;
        else
            return false;
    }
};