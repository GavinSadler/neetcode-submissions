class Solution {

    int dfs(int i, bool inSubarray, vector<int>& nums) {
        int n = nums.size();

        if (i == n - 1) {
            if (inSubarray) {
                return max(0, nums[i]);
            } else {
                return nums[i];
            }
        }

        if (inSubarray) {
            return max(
                0,
                nums[i] + dfs(i + 1, true, nums)
            );
        }

        return max(
            dfs(i + 1, false, nums),
            nums[i] + dfs(i + 1, true, nums)
        );
    }

public:
    int maxSubArray(vector<int>& nums) {
        return dfs(0, false, nums);
    }
};
