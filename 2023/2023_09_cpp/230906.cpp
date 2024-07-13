// 725
// https://leetcode.com/problems/split-linked-list-in-parts/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        
        vector<ListNode*> ret;
        
        int n = 0;
        auto *node = head;
        while (node != nullptr) {
            node = node->next;
            n++;
        }
        
        int x = n / k, r = n % k;
        node = head;
        
        for (int i = 0; i < k; i++) {
            int j = x;
            if (r > 0) {
                r--;
                j += 1;
            }
            ListNode *tmp_head = nullptr, *tmp_iter = nullptr;
            for (; j > 0; j--) {
                ListNode *new_node = new ListNode(node->val);
                node = node->next;
                if (tmp_head == nullptr) {
                    tmp_head = new_node;
                }
                if (tmp_iter != nullptr) {
                    tmp_iter->next = new_node;
                }
                tmp_iter = new_node;
            }
            ret.emplace_back(tmp_head);
        }
        return ret;
    }
};