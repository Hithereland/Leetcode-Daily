//
// Created by z on 5/8/2022.
// # 844

class Solution {
public:
    bool backspaceCompare(string s, string t) {

        std::function<std::string(std::string)> convert = [] (std::string in) {

            std::string ret = "";
            for (auto &c: in) {

                if (c != '#') {
                    ret.push_back(c);
                } else {
                    if (ret.size())
                        ret.pop_back();
                }
            }

            return ret;
        };

        return convert(s) == convert(t);
    }
};

