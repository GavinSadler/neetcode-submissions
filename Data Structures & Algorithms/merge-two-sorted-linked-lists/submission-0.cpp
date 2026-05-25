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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (!list1) return list2;
        if (!list2) return list1;

        ListNode* out;
        ListNode* next;

        if (list1->val < list2->val) {
            out = list1;
            list1 = list1->next;
        } else {
            out = list2;
            list2 = list2->next;
        }

        next = out;

        while(list1 && list2) {
            if (list1->val < list2->val) {
                next->next = list1;
                list1 = list1->next;
            } else {
                next->next = list2;
                list2 = list2->next;
            }
            
            next = next->next;
        }

        while(list1) {
            next->next = list1;
            list1 = list1->next;
            next = next->next;
        }

        
        while(list2) {
            next->next = list2;
            list2 = list2->next;
            next = next->next;
        }

        return out;
    }
};