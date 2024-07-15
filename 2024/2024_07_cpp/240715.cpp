// 2196. Create Binary Tree From Descriptions
// Medium
// https://leetcode.com/problems/create-binary-tree-from-descriptions/

#include <unordered_map>
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
    TreeNode *createBinaryTree(std::vector<std::vector<int>> &descriptions)
    {
        std::unordered_map<int, TreeNode *> val2TreeNode;
        std::unordered_map<int, int> valIsChild;

        // build tree
        for (auto &d : descriptions) {
            int pa = d[0], ch = d[1], isLeft = d[2];
            TreeNode *paNode = val2TreeNode.find(pa) != val2TreeNode.end()
                                   ? val2TreeNode[pa]
                                   : val2TreeNode[pa] = new TreeNode(pa);
            TreeNode *chNode = val2TreeNode.find(ch) != val2TreeNode.end()
                                   ? val2TreeNode[ch]
                                   : val2TreeNode[ch] = new TreeNode(ch);

            (isLeft == 1 ? paNode->left : paNode->right) = chNode;

            // record child
            valIsChild[ch] = 1;
            if (valIsChild[pa] != 1) {
                valIsChild[pa] = 0;
            }
        }

        // find root
        int rootVal = -1;
        for (auto &node : valIsChild) {
            if (node.second == 0) {
                rootVal = node.first;
                break;
            }
        }

        return val2TreeNode[rootVal];
    }
};