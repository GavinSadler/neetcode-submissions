class KthLargest {
    vector<int> data;
    int k;

public:
    KthLargest(int k, vector<int>& nums) {
        this->data = nums;
        this->k = k;
    }
    
    int add(int val) {
        data.push_back(val);
        sort(data.begin(), data.end());
        return data[data.size() - k];
    }
};
