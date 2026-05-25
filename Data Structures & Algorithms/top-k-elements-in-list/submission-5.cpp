class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> nums_count;

        for (int num : nums) {
            nums_count[num]++;
        }

        vector<pair<int, int>> sorted_nums;

        for (auto p : nums_count) {
            sorted_nums.push_back({p.second, p.first});
        }

        sort(sorted_nums.rbegin(), sorted_nums.rend());

        vector<int> out;

        for (int i = 0; i < k; i++) {
            out.push_back(sorted_nums[i].second);
        }

        return out;
    }
};
