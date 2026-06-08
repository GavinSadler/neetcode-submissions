class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int, int>> nums_to_index;

        for(int i = 0; i < nums.size(); i++) {
            nums_to_index.push_back({nums[i], i});
        }

        sort(nums_to_index.begin(), nums_to_index.end());

        int i = 0, j = nums.size() - 1;

        while(i < j && nums_to_index[i].first + nums_to_index[j].first != target) {
            if (nums_to_index[i].first + nums_to_index[j].first < target) {
                i++;
            } else {
                j--;
            }
        }

        return {min(nums_to_index[i].second, nums_to_index[j].second), max(nums_to_index[i].second, nums_to_index[j].second)};
    }
};
