class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        unordered_map<int, int> counts;

        for (int num : nums) {
            counts[num]++;
        }

        vector<pair<int, int>> sorted;

        for (pair<int, int> p : counts) {
            sorted.push_back({p.second, p.first});
        }

        sort(sorted.rbegin(), sorted.rend());

        vector<int> out;

        for( int i = 0; i < k; i++ ) {
            out.push_back(sorted[i].second);
        }

        return out;
    }
};
