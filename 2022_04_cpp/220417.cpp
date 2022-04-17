//
// Created by z on 4/17/2022.
//

class Solution {
public:

    TreeNode* increasingBST(TreeNode* root, TreeNode* rsub=nullptr) {
        if (root == nullptr)
            return rsub;

        rsub = increasingBST(root->right, rsub);
        TreeNode* ret = new TreeNode(root->val, nullptr, rsub);
        ret = increasingBST(root->left, ret);

        return ret;
    }
};
