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
        ListNode* h = new ListNode(0);
        ListNode* t = h;
        ListNode* prev = nullptr;
        
        while(!(l1 == nullptr && l2 == nullptr)) {
            if (l1 != nullptr){
                t->val += l1->val;
                l1 = l1->next;
            }
            if (l2 != nullptr){
                t->val += l2->val;
                l2 = l2->next;
            }
            
            t->next = new ListNode(0);
            
            if (t->val > 9) {
                t->next->val += 1;
                t->val -= 10;
            }
            
            prev = t;
            t = t->next;
        }

        if (t->val == 0) {
            prev->next = nullptr;
            delete t;
        } else {
            t->next = nullptr;
        }

        return h;
    }
};
