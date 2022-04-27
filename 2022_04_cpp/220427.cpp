//
// Created by z on 4/27/2022.
// # 1202

class Solution {
public:

    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {


        size_t n = s.size();
        std::vector<int> vParent(n, -1);
        std::vector<int> &v = vParent;

        std::function<int(int)> find = [&] (int t) -> int {

            if (v[t] == -1)
                return t;

            if (v[v[t]] == -1)
                return v[t];

            v[t] = v[v[t]];

            return find(v[t]);
        };


        for (auto &p: pairs) {

            if (find(p[0]) != find(p[1])) {
                vParent[find(p[1])] = find(p[0]);
            }
        }


        std::unordered_map<int, std::vector<int>> rootToVIndex;
        for (int i = 0; i < n; i++) {

            if (vParent[i] != -1) {
                int root = find(i);
                if (rootToVIndex.find(root) == rootToVIndex.end()) {
                    rootToVIndex[root] = { root, i };
                } else {
                    rootToVIndex[root].push_back(i);
                }
            }
        }


        for (auto &p: rootToVIndex) {

            std::vector<int> &vIndex = p.second;
            sort(vIndex.begin(), vIndex.end());
            std::string newStr;

            for (int i = 0; i < vIndex.size(); i++) {

                newStr += s[vIndex[i]];
            }

            sort(newStr.begin(), newStr.end(), std::less<char>());

            for (int i = 0; i < vIndex.size(); i++) {

                s[vIndex[i]] = newStr[i];
            }
        }


        return s;
    }
};

