// 3169. Count Days Without Meetings
// Medium
// https://leetcode.com/problems/count-days-without-meetings/

#include <algorithm>
#include <vector>

class Solution
{

    typedef struct sched {
        int day;
        bool is_start;
    } sched;

public:
    int countDays(int days, std::vector<std::vector<int>> &meetings) {
        std::vector<sched> schedule(meetings.size() * 2);
        for (int i = 0; i < meetings.size(); i++) {
            schedule[i] = {meetings[i][0], true};
            schedule[i + meetings.size()] = {meetings[i][1], false};
        }

        std::stable_sort(schedule.begin(), schedule.end(), [](sched &a, sched &b) {
            if (a.day != b.day)
                return a.day < b.day;
            else
                return a.is_start;
        });

        int left_cnt = 0, start_day = 0, taken = 0;
        for (auto &sc : schedule) {
            if (sc.is_start) {
                if (left_cnt == 0) {
                    start_day = sc.day;
                }
                left_cnt += 1;
            } else {
                left_cnt -= 1;
                if (left_cnt == 0) {
                    // cout << "start: " << start_day << ", end: " << sc.day << endl;
                    taken += sc.day - start_day + 1;
                }
            }
        }

        return days - taken;
    }
};