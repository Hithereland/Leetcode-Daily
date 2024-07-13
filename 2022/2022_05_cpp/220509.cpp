//
// Created by z on 5/9/2022.
// # 17

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0) return {};
        vector<string> key = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string> ret;

        for (int i = 0; i < key[digits[0]-'0'].size(); i++)
        {
            string x;
            x.push_back(key[digits[0]-'0'][i]);
            ret.push_back(x);
        }

        for (int i = 1; i < digits.size(); i++)
        {
            vector<string> tmp;
            for (auto s1 : ret)
                for (auto s2 : key[digits[i]-'0'])
                {
                    string gen = s1 + s2;
                    tmp.push_back(gen);
                }
            ret = tmp;
        }
        return ret;
    }
};

