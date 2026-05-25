class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0;
        int r = nums.size() - 1;

        int out = nums[0];

        while (l <= r) {
            int m = l + (r - l) / 2;

            if (nums[r] < nums[m]) {
                l = m + 1;
                out = min(out, nums[r]);
            } else {
                r = m - 1;
                out = min(out, nums[m]);
            }
        }

        return out;
    }
};