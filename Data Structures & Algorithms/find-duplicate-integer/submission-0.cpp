class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for (auto& n : nums) {
            int i = abs(n) - 1;

            if (nums[i] < 0) {
                return i + 1;
            }

            nums[i] *= -1;
        }

        return -1;
    }
};