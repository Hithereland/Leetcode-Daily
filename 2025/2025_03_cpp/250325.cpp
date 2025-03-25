// 3394. Check if Grid can be Cut into Sections
// Medium
// https://leetcode.com/problems/check-if-grid-can-be-cut-into-sections/

#include <algorithm>
#include <vector>

class Solution
{

    typedef std::pair<int, int> p;

public:
    bool checkOneDirction(std::vector<p> &rects) {
        std::sort(rects.begin(), rects.end(), [](p a, p b) -> bool {
            if (a.first != b.first) {
                return a.first < b.first;
            } else {
                return a.second > b.second;
            }
        });

        std::vector<p> check;
        for (auto &rect : rects) {
            if (check.empty()) {
                check.push_back(rect);
                continue;
            }

            auto &top = check.back();
            if (rect.first >= top.second) {
                check.push_back(rect);
            } else {
                top.second = std::max(top.second, rect.second);
            }

            if (check.size() > 2) {
                return true;
            }
        }

        return false;
    }

    bool checkValidCuts(int n, std::vector<std::vector<int>> &rectangles) {

        // Horizontal cut means we should check retangles vertically
        // So use rect[1], ret[3]
        // And vertical: rect[0], rect[2]

        std::vector<p> hor(rectangles.size()), ver(rectangles.size());
        for (int i = 0; i < rectangles.size(); i++) {
            auto &rect = rectangles[i];
            hor[i] = {rect[1], rect[3]};
            ver[i] = {rect[0], rect[2]};
        }

        return checkOneDirction(hor) || checkOneDirction(ver);
    }
};