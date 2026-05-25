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
    ListNode* reverseList(ListNode* head) {

        if (head == nullptr) return nullptr;
        if (head->next == nullptr) return head;

        ListNode* n_1 = head->next;
        ListNode* n_2 = head->next->next;

        while (true) {
            n_1->next = head;

            if (head->next == n_1) {
                head->next = nullptr;
            }

            head = n_1;
            n_1 = n_2;

            if (n_2 == nullptr) break;

            n_2 = n_1->next;
        }

        return head;
    }
};