//
// Created by z on 3/24/2022.
// # 881

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int l = 0, r = people.size()-1, ans = 0;

        while (l < r)
        {
            if (people[l] + people[r] <= limit)
            {
                ans++;
                l++;
                r--;
            }
            else
                r--;
        }

        return people.size() - ans;

    }
};

