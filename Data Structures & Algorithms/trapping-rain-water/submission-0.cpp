class Solution {
public:
    int trap(vector<int>& height) {

        if (height.size() < 3) return 0;
        
        int l = 0;
        int r = height.size() - 1;

        int water = 0;

        int maxHeight = 0;

        while (l < r) {

            // cout << "height[" << l << "] " << height[l] << ", " << "height[" << r << "] " << height[r] << " maxHeight " << maxHeight << " : ";
            maxHeight = max(maxHeight, min(height[l], height[r]));
            // cout << maxHeight << "\n";

            if (height[l] <= height[r]) {
                l++;
                water += max(maxHeight - height[l], 0);
            } else {
                r--;
                water += max(maxHeight - height[r], 0);
            }
        }

        return water;
    }
};