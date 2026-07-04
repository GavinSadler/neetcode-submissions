class Solution {
    // int rs(int i, bool inSubarray, vector<int>& nums) {
    //     int n = nums.size();
        
    //     if (i == n - 1) {
    //         if (!inSubarray) {
    //             return nums[i];
    //         } else {
    //             return max(nums[i], 0);
    //         }
    //     }

    //     if (!inSubarray){
    //         return max(
    //             rs(i + 1, false, nums),
    //             nums[i] + rs(i + 1, true, nums)
    //         );
    //     }

    //     return max(
    //         nums[i] + rs(i + 1, true, nums),
    //         0
    //     );
    // }

public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();

        int globalMax = nums[n - 1];
        int runningSum = nums[n - 1];

        for(int i = n - 2; i >= 0; i--) {
            runningSum = max(runningSum + nums[i], nums[i]);
            globalMax = max(globalMax, runningSum);
        }
        
        return globalMax;
    }
};
