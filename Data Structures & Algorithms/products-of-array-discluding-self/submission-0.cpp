class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        int product = 1;
        int zeros = 0;
        int zero_index = -1;

        // for (const auto& n : nums) {
        for (int i = 0; i < nums.size(); i++) {
            int n = nums[i];
            if (n == 0) {
                zeros++;
                zero_index = i;
            } else {
                product *= n;
            }
        }

        if (zeros > 1) {
            vector<int> out(nums.size(), 0);
            return out;
        }

        if (zeros == 1) {
            vector<int> out(nums.size(), 0);
            out[zero_index] = product;
            return out;
        }

        vector<int> out;

        for (const auto& n : nums) {
            out.push_back(product / n);
        }

        return out;
    }
};
