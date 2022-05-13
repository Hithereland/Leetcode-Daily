//
// Created by z on 5/13/2022.
// # 117

class Solution {
public:
    Node* connect(Node* root) {

        std::vector<Node*> leftNode(65, nullptr); // With many times tries I finally get the max depth of the tree.

        std::function<void(Node*, int)> solve = [&] (Node* r, int depth) { // root depth = 1

            if (!r)
                return;

            r->next = leftNode[depth-1];
            leftNode[depth-1] = r;

            solve(r->right, depth+1);
            solve(r->left,  depth+1);
        };


        solve(root, 1);

        return root;
    }
};

