class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> nums_count;

        for (int num : nums) {
            nums_count[num]++;
        }

        vector<vector<int>> freq(nums.size() + 1);

        for (auto entry : nums_count) {
            freq[entry.second].push_back(entry.first);
        }

        vector<int> out;

        for(int i = freq.size() - 1; i > 0; i--) {
            for (int n : freq[i]) {
                out.push_back(n);

                if (out.size() == k) {
                    return out;
                }
            }
        }

        return out;
    }
};
