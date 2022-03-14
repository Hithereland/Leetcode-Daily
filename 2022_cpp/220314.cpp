//
// Created by z on 3/14/2022.
//

class Solution {
public:

    vector<string> splitPath(string path) {
        vector<string> ret;

        for (int i = 0; i < path.size(); i++) {
            if (path[i] == '/')
                ret.push_back("");
            else
                ret[ret.size()-1] += path[i];
        }
        return ret;
    }

    string simplifyPath(string path) {
        stack<string> st;
        vector<string> path_vec = splitPath(path);

        for (auto s : path_vec) {
            if (s == ".")
                continue;
            else if (s == "..")
            {
                if (st.size() != 0)
                    st.pop();
                else
                    continue;
            }
            else if (s == "")
                continue;
            else
                st.push(s);
        }

        string ret = "";
        while (st.size() != 0) {
            ret = "/" + st.top() + ret;
            st.pop();
        }
        if (ret.size())
            return ret;
        else
            return "/";
    }
};

