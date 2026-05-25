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
    void reorderList(ListNode* head) {

        // Grab 2nd half of list

        ListNode* slow = head;
        ListNode* fast = head->next;

        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
        }

        // Seperate slow into 2 lists
        // Head is the first list, h is the second half
        ListNode* h = slow->next;
        slow->next = nullptr;

        // Reverse second half of list
        ListNode* hd = h;
        ListNode* prev = nullptr;
        ListNode* next;

        while(hd != nullptr) {
            next = hd->next;
            hd->next = prev;
            prev = hd;
            hd = next;
        }

        // Compose the two into a new linked list

        ListNode* first = head;
        ListNode* second = prev;

        while(second != nullptr) {
            ListNode* firstNext = first->next;
            ListNode* secondNext = second->next;

            first->next = second;
            second->next = firstNext;

            first = firstNext;
            second = secondNext;
        }

    }
};
