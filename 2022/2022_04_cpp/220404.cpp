//
// Created by z on 4/4/2022.
// # 1721

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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode *tail = head, *opr, *opl;
        while (--k)
        {
            tail = tail->next;
        }
        opl = tail;
        opr = head;
        while (tail->next != nullptr)
        {
            tail = tail->next;
            opr  = opr ->next;
        }
        int tmp = opr->val;
        opr->val = opl->val;
        opl->val = tmp;
        return head;
    }
};

