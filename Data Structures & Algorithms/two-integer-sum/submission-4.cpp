class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, vector<int>> n_to_i;

        for(int i = 0; i < nums.size(); i++) {
            if (n_to_i.contains(nums[i]))
                n_to_i[nums[i]].push_back(i);
            else
                n_to_i[nums[i]] = {i};
        }

        for(int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];

            if(n_to_i.contains(complement)) {
                for(auto &j : n_to_i[complement]) {
                    if (i != j) {
                    return {min(i, j), max(i, j)};
                    }
                }
            }
        }
        
        return {};
    }
};
