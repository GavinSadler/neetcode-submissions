/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {

        unordered_map<Node*, Node*> node_map;

        Node* shallow = nullptr;
        Node* shallowTail = shallow;

        Node* h = head;

        while(h != nullptr) {
            if (shallow == nullptr) {
                shallow = new Node(h->val);
                shallowTail = shallow;
            } else {
                shallowTail->next = new Node(h->val);
                shallowTail = shallowTail->next;
            }
            node_map[shallowTail] = h;
            node_map[h] = shallowTail;
            h = h->next;
        }

        h = shallow;

        while (h != nullptr) {
            h->random = node_map[node_map[h]->random];
            h = h->next;
        }

        return shallow;
    }
};
