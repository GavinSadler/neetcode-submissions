class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> n_to_i;

        for(int i = 0; i < nums.size(); i++) {
            n_to_i[nums[i]] = i;
        }

        for(int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];

            auto it = n_to_i.find(complement);

            if (it != n_to_i.end() && it->second != i) {
                return {i, it->second};
            }
        }
        
        return {};
    }
};
