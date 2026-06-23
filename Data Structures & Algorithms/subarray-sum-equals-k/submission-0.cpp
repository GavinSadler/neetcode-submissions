class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int res = 0;

        int currSum = 0;

        unordered_map<int, int> prefixSums;

        prefixSums[0] = 1;

        for(int num : nums) {
            currSum += num;

            int diff = currSum - k;

            res += prefixSums[diff];

            prefixSums[currSum]++;
        }

        return res;

        // [ 5, 3, 6, 2, 4 ] k = 8
        // ps{ 0 : 1, 5 : 1, 8 : 1, 14: 1, }
        // [ 5, 3, 6, 2, 4 ] k = 8
        
        // [ 5, 3, 6, 2, 4 ] k = 8
        // [ 5, 3, 6, 2, 4, 0 ] k = 8
        // [ 5, 5, 3, 6, 2, 4 ] k = 8
        // [ 0, 5, 3, 6, 2, 4 ] k = 8
    }
};