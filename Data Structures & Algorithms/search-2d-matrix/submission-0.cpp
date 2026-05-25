class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int l = 0;
        int r = matrix.size() - 1;
        int m;

        while (l <= r) {
            m = l + (r - l) / 2;

            if (matrix[m][0] < target) {
                l = m + 1;
            } else if (matrix[m][0] > target) {
                r = m - 1;
            } else {
                return true;
            }
        }

        if (r < 0) return false;

        // cout << l << "\n";
        int i = r;
        // cout << matrix[i][0];

        l = 0;
        r = matrix[i].size() - 1;

        while (l <= r) {
            m = l + (r - l) / 2;

            if (matrix[i][m] < target) {
                l = m + 1;
            } else if (matrix[i][m] > target) {
                r = m - 1;
            } else {
                return true;
            }
        }

        return false;
    }
};