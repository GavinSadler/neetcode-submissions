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

        // vector<vector<int>> dp(2, vector(nums.size(), 0));

        // dp[0][n - 1] = nums[n - 1];
        // dp[1][n - 1] = max(0, nums[n - 1]);

        int top    = nums[n - 1];
        int bottom = max(0, nums[n - 1]);

        for(int i = n - 2; i >= 0; i--) {
            top = max(
                top,
                nums[i] + bottom
            );
            bottom = max(
                nums[i] + bottom,
                0
            );
        }


        return top;
    }
};
