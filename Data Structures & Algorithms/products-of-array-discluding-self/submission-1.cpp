class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        if (nums.size() == 0) {
            vector<int> out;
            return out;
        }
        
        if (nums.size() == 1) {
            vector<int> out;
            out.push_back(nums[0]);
            return out;
        }

        vector<int> prefix(nums.size(), 0);
        vector<int> postfix(nums.size(), 0);

        int prod = 1;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                break;
            }

            prod *= nums[i];
            prefix[i] = prod;
        }

        prod = 1;

        for (int i = nums.size() - 1; i >= 0; i--) {
            if (nums[i] == 0) {
                break;
            }

            prod *= nums[i];
            postfix[i] = prod;
        }

        vector<int> out(nums.size(), 0);
        
        out[0] = postfix[1];
        out[nums.size() - 1] = prefix[nums.size() - 2];

        for (int i = 1; i < nums.size() - 1; i++) {
            out[i] = prefix[i - 1] * postfix[i + 1];
        }

        return out;
    }
};
