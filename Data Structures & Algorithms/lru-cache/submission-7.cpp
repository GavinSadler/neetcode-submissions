class DoubleListNode {
    public:
    DoubleListNode* next;
    DoubleListNode* prev;
    int val;

    DoubleListNode(int v) : val{v}, next{nullptr}, prev{nullptr} {}

    ~DoubleListNode() {
        val = 0;
        next = nullptr;
        prev = nullptr;
    }

};

class LRUCache {
    DoubleListNode* head;
    DoubleListNode* tail;
    unordered_map<int, DoubleListNode*> key_to_node;
    unordered_map<DoubleListNode*, int> node_to_key;

public:
    LRUCache(int capacity) {
        head = new DoubleListNode(-1);
        tail = head;

        for(int i = 1; i < capacity; i++) {
            DoubleListNode* n = new DoubleListNode(-1);
            n->prev = tail;
            n->prev->next = n;
            tail = n;
        }
    }
    
    int get(int key) {
        if(key_to_node.find(key) == key_to_node.end()) {
            return -1;
        }

        DoubleListNode* n = key_to_node[key];

        if (n == tail && n->prev != nullptr) {
            tail = tail->prev;
        }

        if (n != head) {
            if (n->prev != nullptr) {
                n->prev->next = n->next;
            }

            if (n->next != nullptr){
                n->next->prev = n->prev;
            }

            head->prev = n;
            n->next = head;

            head = n;
        }

        return n->val;
    }
    
    void put(int key, int value) {
        
        // Simultaneously check if the key is present
        // and if it is move it to the head
        if(get(key) != -1) {
            head->val = value;
            return;
        }

        DoubleListNode* newHead = new DoubleListNode(value);
        key_to_node[key] = newHead;
        node_to_key[newHead] = key;

        newHead->next = head;
        head->prev = newHead;

        head = newHead;

        // Evict tail

        DoubleListNode* newTail = tail->prev;

        if(node_to_key.find(tail) != node_to_key.end()) {
            key_to_node.erase(node_to_key[tail]);
            node_to_key.erase(tail);
        }

        delete tail;

        newTail->next = nullptr;

        tail = newTail;
    }
};
