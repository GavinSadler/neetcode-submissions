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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* out = nullptr;
        ListNode* outTail = nullptr;

        int smallest = INT_MAX;
        int iSmallest = -1;

        for(int i = 0; i < lists.size(); i++) {
            ListNode* l = lists[i];
            if (l != nullptr && l->val < smallest) {
                iSmallest = i;
                smallest = l->val;
            }
        }

        if (iSmallest == -1) {
            return nullptr;
        }

        // Isolate the smallest node as our output
        ListNode* s = lists[iSmallest];

        out = s;

        lists[iSmallest] = s->next;
        s->next = nullptr;
        
        outTail = out;

        while(iSmallest != -1) {
            smallest = INT_MAX;
            iSmallest = -1;

            for(int i = 0; i < lists.size(); i++) {
                ListNode* l = lists[i];
                if (l != nullptr && l->val < smallest) {
                    iSmallest = i;
                    smallest = l->val;
                }
            }

            if (iSmallest != -1) {
                s = lists[iSmallest];

                outTail->next = s;

                lists[iSmallest] = s->next;
                
                outTail = outTail->next;
                outTail->next = nullptr;
            }

        }

        return out;
    }
};
