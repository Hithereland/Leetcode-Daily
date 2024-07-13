//
// Created by z on 5/8/2022.
// # 456

class Solution {
public:
    bool find132pattern(vector<int>& nums) {

        std::stack<int> st;
        int n = nums.size(), mid = INT_MIN;

        for (int i = n-1; i >= 0; i--) {

            int x = nums[i];
            if (x < mid)
                return 1;

            while (st.size() != 0 && x > st.top()) {

                mid = mid > st.top() ? mid : st.top();
                st.pop();
            }

            st.push(x);
        }

        return 0;
    }
};

