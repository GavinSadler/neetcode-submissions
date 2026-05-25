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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* leftovers = nullptr;
        vector<ListNode*> sections;

        int count = 1;

        ListNode* h = head;
        ListNode* t = h;

        while (h != nullptr) {
            while(t->next && count < k) {
                t = t->next;
                count++;
            }

            ListNode* nxt = t->next;
            t->next = nullptr;

            if (count == k) {
                sections.push_back(h);
            } else {
                leftovers = h;
            }

            count = 1;

            h = nxt;
            t = h;
        }

        // cout << "Leftovers:\n";

        // while(leftovers) {
        //     cout << leftovers->val << ", ";
        //     leftovers = leftovers->next;
        // }
        // cout << "\n";

        // for(int i = 0; i < sections.size(); i++) {
        //     ListNode* p = sections[i];

        //     cout << i << "\n\t";

        //     while(p) {
        //         cout << p->val << ", ";
        //         p = p->next;
        //     }

        //     cout << "\n";

        // }

        // return 0;

        for (ListNode*& h : sections) {
            ListNode* prev = nullptr;
            ListNode* curr = h;
            ListNode* nxt = h->next;

            while(h != nullptr) {
                nxt = h->next;
                h->next = prev;
                prev = h;
                h = nxt;
            }

            h = prev;
        }

        ListNode* dummyHead = new ListNode(-1);
        ListNode* tail = dummyHead;

        for(ListNode* h : sections) {
            tail->next = h;

            while(h->next != nullptr) {
                h = h->next;
            }

            tail = h;
        }

        tail->next = leftovers;

        return dummyHead->next;
    }
};
