// 2096. Step-By-Step Directions From a Binary Tree Node to Another
// Medium
// https://leetcode.com/problems/step-by-step-directions-from-a-binary-tree-node-to-another/submissions/

#include <algorithm>
#include <string>

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
    // Return true if success
    static bool dfsPath(TreeNode *root, int target, std::string &path)
    {
        if (root == nullptr) {
            return false;
        }
        if (root->val == target) {
            return true;
        }

        path.push_back('L');
        if (dfsPath(root->left, target, path)) return true;
        path.pop_back();

        path.push_back('R');
        if (dfsPath(root->right, target, path)) return true;
        path.pop_back();

        return false;
    }

    std::string getDirections(TreeNode *root, int startValue, int destValue)
    {
        std::string root_to_start, root_to_dest;
        dfsPath(root, startValue, root_to_start);
        dfsPath(root, destValue, root_to_dest);

        int after_prefix_idx = 0,
            minor_size = std::min(root_to_start.size(), root_to_dest.size());
        while (after_prefix_idx < minor_size) {
            if (root_to_start[after_prefix_idx] ==
                root_to_dest[after_prefix_idx]) {
                after_prefix_idx++;
            } else {
                break;
            }
        }

        return std::string(root_to_start.size() - after_prefix_idx, 'U') +
               root_to_dest.substr(after_prefix_idx);
    }
};
