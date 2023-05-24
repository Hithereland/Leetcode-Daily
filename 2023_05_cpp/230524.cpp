// No. 2542
// https://leetcode.com/problems/maximum-subsequence-score/

class Solution {
public:

    typedef long long ll;

    typedef struct cell {
        int add, mut;
    } cell;

    static bool cmp (cell a, cell b) {
        if (a.mut != b.mut)
            return a.mut > b.mut;
        else
            return a.add < b.add;
    }

    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {

        int n = nums1.size();
        vector<cell> v(n);
        priority_queue<int, vector<int>, greater<int> > pq;
        for (int i = 0; i < n; i++) {
            v[i].add = nums1[i], v[i].mut = nums2[i];
        }

        sort(v.begin(), v.end(), cmp);

        ll tmp_mut = v[k-1].mut, tmp_sum = 0, ret = 0;
        for (int i = 0; i < k; i++) {
            tmp_sum += v[i].add;
            pq.push(v[i].add);
        }

        ret = tmp_sum * tmp_mut;

        int idx = k;
        while (idx < n) {
            while (idx < n && v[idx].mut == tmp_mut) {
                pq.push(v[idx].add);
                tmp_sum += v[idx].add;
                tmp_sum -= pq.top();
                pq.pop();
                idx++;
            }
            ret = max(ret, tmp_mut * tmp_sum);
            if (idx == n)
                break;
            tmp_mut = v[idx].mut;
        }

        return ret;
    }
};