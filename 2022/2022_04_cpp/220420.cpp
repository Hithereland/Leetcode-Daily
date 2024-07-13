//
// Created by z on 4/20/2022.
// # 173

class BSTIterator {
public:

    std::vector<int> arr;
    int idx;

    BSTIterator(TreeNode* root) {

        std::function<void(TreeNode*)> InorderTraverseMakeArr = [&] (TreeNode* r) -> void {
            if (r == nullptr)
                return;
            InorderTraverseMakeArr(r->left);
            arr.push_back(r->val);
            InorderTraverseMakeArr(r->right);
            return;
        };

        InorderTraverseMakeArr(root);
        idx = -1;
    }

    int next() {
        return arr[++idx];
    }

    bool hasNext() {
        return arr.size() > idx+1;
    }
};