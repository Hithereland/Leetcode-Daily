// 92
// https://leetcode.com/problems/reverse-linked-list-ii/

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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (head == nullptr) {
            return head;
        }
        
        ListNode *l = nullptr, *m = head, *r = m->next;
        int i = 0;
        while (i < left - 1) {
            i++;
            l = m;
            m = m->next;
            r = r->next;
        }
        while (i < right - 1) {
            i++;
            r = r->next;
        }

        ListNode *to_be_prev = m->next, *to_be_next = r;
        while (m != r) {
            m->next = to_be_next;
            to_be_next = m;
            m = to_be_prev;
            if (to_be_prev != nullptr) {
                to_be_prev = to_be_prev->next;
            }
        }
        if (l == nullptr) {
            head = to_be_next;
        } else {
            l->next = to_be_next;
        }
        
        return head;
    }
};