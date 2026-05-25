class Solution {
public:
    int binarySearch(vector<int>& nums, int target, int left, int right) {
        while (left <= right) {
            int m = left + (right - left) / 2;

            if (nums[m] == target) {
                return m;
            } else if (nums[m] < target) {
                left = m + 1;
            } else {
                right = m - 1;
            }
        }

        return -1;
    }

    int search(vector<int>& nums, int target) {
        
        int l = 0;
        int r = nums.size() - 1;

        while (l < r) {
            int m = l + (r - l) / 2;

            if (nums[m] > nums[r]) {
                l = m + 1;
            } else {
                r = m;
            }
        }

        int iMin = l;

        int bsl = binarySearch(nums, target, iMin, nums.size() - 1);
        
        if (bsl == -1) {
            return binarySearch(nums, target, 0, iMin - 1);
        }

        return bsl;
    }
};