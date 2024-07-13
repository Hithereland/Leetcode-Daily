#include <algorithm>
#include <string>
#include <vector>

class Solution {
public:
    typedef struct {
        int pos;
        int health;
        bool is_going_right;
        int order;
    } Robot;

    static std::vector<int> survivedRobotsHealths(std::vector<int>& positions,
                                                  std::vector<int>& healths,
                                                  std::string directions) {

        std::vector<Robot> v_ans, v_goRight, v_data;

        // prepare data for processiong
        for (int i = 0; i < directions.size(); i++) {
            v_data.push_back(
                {positions[i], healths[i], directions[i] == 'R', i});
        }

        std::sort(v_data.begin(), v_data.end(),
                  [](Robot a, Robot b) -> bool { return a.pos < b.pos; });

        // process
        for (auto& robot : v_data) {
            if (robot.is_going_right) {
                v_goRight.push_back(robot);
            } else {
                // judge
                while (!v_goRight.empty()) {
                    if (v_goRight[v_goRight.size() - 1].health < robot.health) {
                        robot.health -= 1;
                        v_goRight.pop_back();
                        continue;
                    } else if (v_goRight[v_goRight.size() - 1].health ==
                               robot.health) {
                        robot.health = 0;
                        v_goRight.pop_back();
                        break;
                    } else {
                        robot.health = 0;
                        v_goRight[v_goRight.size() - 1].health -= 1;
                        break;
                    }
                }
                if (robot.health != 0) {
                    v_ans.push_back(robot);
                }
            }
        }
        v_ans.insert(v_ans.end(), v_goRight.begin(), v_goRight.end());

        // gen return data
        std::sort(v_ans.begin(), v_ans.end(),
                  [](Robot a, Robot b) -> bool { return a.order < b.order; });
        std::vector<int> ret;
        for (auto& robot : v_ans) {
            ret.push_back(robot.health);
        }
        return ret;
    }
};

int main() {
    std::vector<int> positions = {3, 5, 2, 6}, healths = {10, 10, 15, 12};
    std::string directions = "RLRL";
    Solution::survivedRobotsHealths(positions, healths, directions);
}
/*
[3,5,2,6]
[10,10,15,12]
"RLRL"
*/
