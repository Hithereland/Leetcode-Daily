//
// Created by z on 5/15/2022.
// # 1302

class Solution {
public:
    int deepestLeavesSum(TreeNode* root) {

        std::function<std::pair<int, int>(TreeNode*)> solve = [&] (TreeNode* rt) -> std::pair<int, int> {

            if (!rt) {
                return {0, 0};
            }

            if (rt->left == nullptr && rt->right == nullptr) {
                return {rt->val, 1};
            }

            std::pair<int, int> l = solve(rt->left), r = solve(rt->right);

            if (l.second == r.second) {
                return {l.first + r.first, l.second + 1};
            } else if (l.second < r.second) {
                return {r.first, r.second + 1};
            } else {
                return {l.first, l.second + 1};
            }
        };

        std::pair<int, int> ret = solve(root);
        return ret.first;
    }
};

