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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* h;

        int l1_length = 0;
        h = l1;

        while(h != nullptr) {
            h = h->next;
            l1_length++;
        }

        int l2_length = 0;
        h = l2;

        while(h != nullptr) {
            h = h->next;
            l2_length++;
        }

        int l1_val = 0;
        h = l1;

        for(int i = 0; i < l1_length; i++) {
            l1_val += h->val * pow(10, i);
            h = h->next;
        }

        int l2_val = 0;
        h = l2;

        for(int i = 0; i < l2_length; i++) {
            l2_val += h->val * pow(10, i);
            h = h->next;
        }

        int sum = l1_val + l2_val;

        h = new ListNode(0);
        ListNode* prev = h;
        ListNode* t = h;

        while(sum > 0) {
            t->val = sum % 10;
            sum /= 10;
            
            prev = t;
            t->next = new ListNode(0);
            t = t->next;
        }

        if (t != h) {
            delete t;
        }

        prev->next = nullptr;        

        return h;
    }
};
