class Solution {
    int rs(int i, bool inSubarray, vector<int>& nums) {
        int n = nums.size();
        
        if (i == n - 1) {
            if (!inSubarray) {
                return nums[i];
            } else {
                return max(nums[i], 0);
            }
        }

        if (!inSubarray){
            return max(
                rs(i + 1, false, nums),
                nums[i] + rs(i + 1, true, nums)
            );
        }

        return max(
            nums[i] + rs(i + 1, true, nums),
            0
        );
    }

public:
    int maxSubArray(vector<int>& nums) {
        
        // return rs(0, false, nums);

        int n = nums.size();

        //       0 1 2 3 4 5 ...
        // false
        // true
        vector<vector<int>> dp(2, vector(nums.size(), 0));

        // if (!inSubarray) {
        //     return nums[i];
        // } else {
        //     return max(nums[i], 0);
        // }

        dp[0][n - 1] = nums[n - 1];
        dp[1][n - 1] = max(0, nums[n - 1]);

        // if (!inSubarray){
        //     return max(
        //         rs(i + 1, false, nums),
        //         nums[i] + rs(i + 1, true, nums)
        //     );
        // }

        // return max(
        //     nums[i] + rs(i + 1, true, nums),
        //     0
        // );

        for(int i = n - 2; i >= 0; i--) {
            dp[0][i] = max(
                dp[0][i + 1],
                nums[i] + dp[1][i + 1]
            );
            dp[1][i] = max(
                nums[i] + dp[1][i + 1],
                0
            );
        }

        // for(int i = 0; i < n; i++) {
        //     cout << nums[i] << ", ";
        // }

        // cout << "\n";
        
        // for(int i = 0; i < n; i++) {
        //     cout << dp[0][i] << ", ";
        // }

        // cout << "\n";
        
        // for(int i = 0; i < n; i++) {
        //     cout << dp[1][i] << ", ";
        // }

        return dp[0][0];
    }
};
