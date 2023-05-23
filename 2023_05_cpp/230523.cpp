// No. 703
// https://leetcode.com/problems/kth-largest-element-in-a-stream/submissions/

class KthLargest {
private:
    struct cmp {
        bool operator() (int a, int b) {
            return a > b;
        }
    };
    
    priority_queue<int, vector<int>, cmp> pq;
    
public:
    KthLargest(int k, vector<int>& nums) {
        pq = priority_queue<int, vector<int>, cmp>(nums.begin(), nums.end());
        while (pq.size() > k) {
            pq.pop();
        }
        if (pq.size() < k) {
            pq.push(INT_MIN);
        }
    }
    
    int add(int val) {
        pq.push(val);
        pq.pop();
        return pq.top();
    }
};