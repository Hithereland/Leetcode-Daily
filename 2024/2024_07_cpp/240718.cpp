// 1530. Number of Good Leaf Nodes Pairs
// Medium
// https://leetcode.com/problems/number-of-good-leaf-nodes-pairs/

#include <algorithm>
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

class Solution_BETTER_N2
{
public:
    int ans = 0;
    std::vector<int> dfsLeavesByDistances(TreeNode *root, int d)
    {
        if (!root) return {};
        // This node IS leaf node, so ret[0] == 1 means there is only 1 leaf
        // node with distance of 0
        if (!root->left && !root->right) return {1};

        auto left = dfsLeavesByDistances(root->left, d);
        auto right = dfsLeavesByDistances(root->right, d);

        // Prepare ret for parent to use
        std::vector<int> ret(d, 0);
        for (int i = 0;
             i < left.size() && i < d - 1 /* Drop nodes with long distance */;
             i++) {
            ret[i + 1] += left[i];
        }
        for (int i = 0;
             i < right.size() && i < d - 1 /* Drop nodes with long distance */;
             i++) {
            ret[i + 1] += right[i];
        }

        if (right.size() == 0 || left.size() == 0) {
            return ret;
        }

        auto right_prefix_sum = right;
        for (int i = 1; i < right_prefix_sum.size(); i++) {
            right_prefix_sum[i] += right_prefix_sum[i - 1];
        }

        // Set left distance as i, we count how many right leaf nodes are valid
        for (int i = 1; i <= left.size(); i++) {
            // Leaf nodes from right with distance leq j are valid
            int j = std::min(d - i, (int)right.size());
            if (j < 1) {
                break;
            }
            // Nums of distance i actually recorded as left[i-1]
            ans += left[i - 1] * right_prefix_sum[j - 1];
        }

        return ret;
    }
    int countPairs(TreeNode *root, int distance)
    {
        dfsLeavesByDistances(root, distance);
        return ans;
    }
};

class Solution_EVEN_BETTER_N3
{
public:
    int ans = 0;
    std::vector<int> dfsLeavesDistances(TreeNode *root, int d)
    {
        if (!root) return {};
        if (!root->left && !root->right) return {1};

        std::vector<int> left = dfsLeavesDistances(root->left, d),
                         right = dfsLeavesDistances(root->right, d), ret;

        for (auto &a : left) {
            for (auto &b : right) {
                if (a + b <= d) {
                    ans++;
                }
            }
        }

        for (auto &a : left) {
            if (a < d - 1) ret.push_back(a + 1);
        }
        for (auto &b : right) {
            if (b < d - 1) ret.push_back(b + 1);
        }

        return ret;
    }

    int countPairs(TreeNode *root, int distance)
    {
        dfsLeavesDistances(root, distance);
        return ans;
    }
};

class Solution_SUCKS_MAYBE_N2
{
public:
    std::unordered_map<TreeNode *, std::vector<int>> leaf_num_by_depth_of;
    std::vector<int> mergeNumOfLeafFrom(std::vector<int> &left,
                                        std::vector<int> &right)
    {
        std::vector<int> ret = {0};
        for (int i = 0; i < left.size(); i++) {
            while (ret.size() <= i + 1) ret.push_back(0);
            ret[i + 1] += left[i];
        }
        for (int i = 0; i < right.size(); i++) {
            while (ret.size() <= i + 1) ret.push_back(0);
            ret[i + 1] += right[i];
        }
        return ret;
    }

    void countLeavesOf(TreeNode *root)
    {
        if (root->left == nullptr && root->right == nullptr) {
            leaf_num_by_depth_of[root] = {1};
            return;
        }
        if (root->left) countLeavesOf(root->left);
        if (root->right) countLeavesOf(root->right);
        std::vector<int> left = root->left ? leaf_num_by_depth_of[root->left]
                                           : std::vector<int>({});
        std::vector<int> right = root->right ? leaf_num_by_depth_of[root->right]
                                             : std::vector<int>({});
        leaf_num_by_depth_of[root] = mergeNumOfLeafFrom(left, right);
    }

    int dfsCountPairsHelper(TreeNode *root, int distance)
    {
        int ans = 0;
        if (root->left) ans += dfsCountPairsHelper(root->left, distance);
        if (root->right) ans += dfsCountPairsHelper(root->right, distance);

        if (!(root->left && root->right)) {
            return ans;
        }

        std::vector<int> prefix_of_leaf_num_right =
            leaf_num_by_depth_of[root->right];

        for (int i = 1; i < prefix_of_leaf_num_right.size(); i++) {
            prefix_of_leaf_num_right[i] += prefix_of_leaf_num_right[i - 1];
        }

        for (int i = 1; i <= leaf_num_by_depth_of[root->left].size(); i++) {
            if (i == distance) break;
            ans += leaf_num_by_depth_of[root->left][i - 1] *
                   prefix_of_leaf_num_right[std::min(
                       distance - i - 1,
                       int(prefix_of_leaf_num_right.size() - 1))];
        }

        return ans;
    }

    int countPairs(TreeNode *root, int distance)
    {
        countLeavesOf(root);
        return dfsCountPairsHelper(root, distance);
    }
};
