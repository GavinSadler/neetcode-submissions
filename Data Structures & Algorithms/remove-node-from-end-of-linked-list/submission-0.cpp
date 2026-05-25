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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int l = 0;

        ListNode* h = head;

        while (h != nullptr) {
            h = h->next;
            l++;
        }

        int index = l - n;

        if (index == 0) {
            return head->next;
        }

        ListNode* p = head;

        for(int i = 0; i < index - 1; i++) {
            p = p->next;
        }

        ListNode* nxt = p->next->next;
        p->next = nxt;

        return head;
    }
};
