//
// Created by z on 2022/5/23.
// # 1379

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {

        TreeNode* ret = nullptr;

        std::function<void(TreeNode*, int)> Traverse = [&] (TreeNode* r, int t) {

            if (r == nullptr) {
                return;
            }

            if (r->val == t) {
                ret = r;
                return;
            }

            Traverse(r->left,  t);
            Traverse(r->right, t);
        };

        Traverse(cloned, target->val);

        return ret;
    }
};
