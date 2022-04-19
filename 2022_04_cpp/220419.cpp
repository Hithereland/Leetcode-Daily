//
// Created by z on 4/19/2022.
// # 99

class Solution {
public:
    void recoverTree(TreeNode* root) {
        std::vector<int> arr;
        int idx = 0;
        std::function<void(TreeNode*)> InorderTraverseMakeArr = [&] (TreeNode* r) -> void {
            if (r == nullptr)
                return;
            InorderTraverseMakeArr(r->left);
            arr.push_back(r->val);
            InorderTraverseMakeArr(r->right);
        };
        std::function<void(TreeNode*)> InorderTraverseModiTree = [&] (TreeNode *r) -> void {
            if (r == nullptr)
                return;
            InorderTraverseModiTree(r->left);
            r->val = arr[idx++];
            InorderTraverseModiTree(r->right);
        };
        InorderTraverseMakeArr(root);
        std::sort(arr.begin(), arr.end());
        InorderTraverseModiTree(root);
        return;
    }
};

