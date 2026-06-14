class MyCircularQueue {
    vector<int> q;
    int front = 0;
    int back = -1;
    int k = -1;
    int size = 0;
public:
    MyCircularQueue(int k) {
        q = vector<int>(k, -1);
        this->k = k;
    }
    
    bool enQueue(int value) {
        if (isFull()) {
            return false;
        }

        back = (back + 1) % k;
        q[back] = value;

        size++;
        
        return true;
    }
    
    bool deQueue() {
        if (isEmpty()) {
            return false;
        }

        front = (front + 1) % k;

        size--;
        
        return true;
    }
    
    int Front() {
        if (isEmpty()) {
            return -1;
        }

        return q[front];
    }
    
    int Rear() {
        if (isEmpty()) {
            return -1;
        }
        
        return q[back];
    }
    
    bool isEmpty() {
        return size == 0;
    }
    
    bool isFull() {
        return size == k;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */