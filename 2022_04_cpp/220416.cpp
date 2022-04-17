//
// Created by z on 4/17/2022.
// # 538

class Solution {
public:

    static int rec_help(TreeNode* root, int x) {
        int sum = 0;
        if (root != nullptr)
        {
            sum += rec_help(root->right, x);
            sum += root->val;
            root->val = sum + x;
            sum += rec_help(root->left, sum+x);
        }
        return sum;
    }

    TreeNode* convertBST(TreeNode* root) {
        rec_help(root, 0);
        return root;
    }
};

