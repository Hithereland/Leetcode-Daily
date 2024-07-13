//
// Created by z on 4/18/2022.
// # 230

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        std::vector<int> ans;
        std::function<void(TreeNode*)> InorderTraverse = [&] (TreeNode* r) {
            if (r == nullptr)
                return;
            InorderTraverse(r->left);
            ans.push_back(r->val);
            InorderTraverse(r->right);
        };
        InorderTraverse(root);
        return ans[k-1];
    }
};