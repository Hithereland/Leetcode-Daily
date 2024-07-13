//
// Created by z on 4/16/2022.
// # 669

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    TreeNode* trimBST(TreeNode* root, int low, int high) {

        if (root != nullptr)
        {
            TreeNode *l = root->left, *r = root->right;
            int val = root->val;
            if (val > high)
                return trimBST(l, low, high);
            if (val < low)
                return trimBST(r, low, high);

            root->left = trimBST(l, low, high);
            root->right = trimBST(r, low, high);
        }

        return root;
    }
};

