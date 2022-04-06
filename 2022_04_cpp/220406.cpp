//
// Created by z on 4/6/2022.
// # 923
// I do not want to code it again

class Solution {
public:

    int threeSumMulti(vector<int>& arr, int target) {
        unordered_map<int, long long> m, copy_of_m, tmp_copy_of_m; // primary
        for (auto &x: arr)
            m.find(x) == m.end() ? (m[x] = 1) : m[x]++;
        copy_of_m = m;

        int ans = 0, mdl = 1000000007;

        for (auto &p: m) // all diff
        {
            int a = p.first;
            tmp_copy_of_m = m;
            for (auto &q: m)
            {
                int b = q.first;
                int t = target - a - b;
                if (a == b || a == t || b == t)
                    continue;
                if(m.find(t) != m.end())
                    ans += (m[a]*m[b]*m[t])%mdl;
                ans %= mdl;
                m[b] = 0;
            }
            m = tmp_copy_of_m;
            m[a] = 0;
        }
        m = copy_of_m; // restoration

        for (auto &p: m) // 2 same
        {
            int a = p.first;
            int t = target - a - a;
            if (t == a)
                continue;
            if (m.find(t) != m.end())
                ans += (m[a]*(m[a]-1)*m[t]/2)%mdl;
            ans %= mdl;
        }

        int one_third = target / 3;
        if (one_third * 3 == target && m.find(one_third) != m.end())
        {
            int x = one_third;
            ans += (m[x]*(m[x]-1)*(m[x]-2)/6)%mdl;
            ans %= mdl;
        }

        return ans;
    }
};

