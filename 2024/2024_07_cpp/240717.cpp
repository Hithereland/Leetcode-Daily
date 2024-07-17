#include <unordered_set>
#include <vector>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right)
    {
    }
};

class Solution
{
public:
    std::unordered_set<int> to_delete_set;
    std::vector<TreeNode *> ret;
    void dfsDelUntil(TreeNode *&root)
    {
        if (root == nullptr) return;

        if (root->left) dfsDelUntil(root->left);
        if (root->right) dfsDelUntil(root->right);

        if (to_delete_set.find(root->val) != to_delete_set.end()) {
            if (root->left) ret.push_back(root->left);
            if (root->right) ret.push_back(root->right);
            delete root;
            root = nullptr;
        }
        return;
    }

    std::vector<TreeNode *> delNodes(TreeNode *root,
                                     std::vector<int> &to_delete)
    {
        to_delete_set =
            std::unordered_set<int>(to_delete.begin(), to_delete.end());
        dfsDelUntil(root);
        if (root) ret.push_back(root);
        return ret;
    }
};