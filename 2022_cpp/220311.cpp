//
// Created by z on 3/11/2022.
//

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
    ListNode* rotateRight(ListNode* head, int k) {
        int len = 0;
        ListNode* tail = head;

        while (tail != nullptr) {
            tail = tail->next;
            len++;
        }

        if (len <= 1) return head;
        k %= len;

        if (!k) return head;

        ListNode* ItSucks = head;
        k = len - k;
        for (int i = 0; i < k - 1; i++)
            ItSucks = ItSucks->next;

        ListNode *ret = ItSucks->next;
        ItSucks->next = nullptr;
        tail = ret;
        while (tail->next != nullptr)
            tail = tail->next;
        tail->next = head;
        return ret;

    }
};
