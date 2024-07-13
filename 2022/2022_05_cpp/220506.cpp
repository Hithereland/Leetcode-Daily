//
// Created by z on 5/8/2022.
// # 1209

class Solution {
public:
    string removeDuplicates(string s, int k) {

        std::vector<std::pair<char, int>> st;
        int idx = 0;
        for (auto x: s) {

            if (!st.size()) {
                st.push_back(std::pair<char, int>(x, 1));
                continue;
            }

            char prevCh = st[st.size()-1].first;
            int prevTimes = st[st.size()-1].second;

            if (x == prevCh) {

                int times = prevTimes + 1;
                st.push_back(std::pair<char, int>(x, times));

                if (times == k)
                    for (int j = 0; j < k; j++)
                        st.pop_back();

            } else {

                st.push_back(std::pair<char, int>(x, 1));
            }
        }

        std::string ret;

        for (auto x: st) {

            ret.append(1, x.first);
        }

        return ret;
    }
};

