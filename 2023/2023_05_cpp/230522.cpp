// No. 347
// https://leetcode.com/problems/top-k-frequent-elements/

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for (auto &x: nums) {
            m[x]++;
        }
        
        priority_queue<pair<int, int>> pq;
        for (auto &p: m) {
            pq.push({p.second, p.first});
        }
        
        vector<int> ret;
        while (k--) {
            ret.emplace_back(pq.top().second);
            pq.pop();
        }
        
        return ret;
    }
};