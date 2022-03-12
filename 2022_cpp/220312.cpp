//
// Created by z on 3/12/2022.
//

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {

        Node *travel = head;
        if (head == nullptr) return nullptr;

        unordered_map<Node*, Node*> m;
        Node* dummy = new Node(-1), * tail = dummy;

        while (travel != nullptr) {
            tail->next = new Node(travel->val);
            m[travel]  = tail->next;
            tail       = tail->next;
            travel     = travel->next;
        }

        travel = head;
        tail   = dummy->next;

        while (travel) {
            tail->random = m[travel->random];
            travel       = travel->next;
            tail         = tail->next;
        }

        Node *ret = dummy->next;
        delete dummy;
        return ret;

    }
};