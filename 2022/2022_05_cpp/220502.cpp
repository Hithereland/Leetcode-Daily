//
// Created by z on 5/8/2022.
// # 905

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {

        std::vector<int> odd, even;
        for (auto &x: nums) {

            ( x&1 ? &odd : &even ) -> push_back(x);
        }
        even.insert(even.end(), odd.begin(), odd.end());
        return even;
    }
};

