//
// Created by z on 4/8/2022.
// # 703

class KthLargest {
public:

    priority_queue<int, vector<int>, greater<int> > q;

    KthLargest(int k, vector<int>& nums) {
        for (auto &x: nums)
            q.push(x);
        int t = nums.size() - k;
        while(t-- > 0)
            q.pop();
        if (q.size() < k)
            q.push(INT_MIN);
    }

    int add(int val) {
        q.push(val);
        q.pop();
        return q.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */

