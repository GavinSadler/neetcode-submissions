class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        for (auto it = nums.begin(); it < nums.end(); it++)
            cout << *it << ", ";
        cout << "\n";

        vector<vector<int>> out;

        for (auto it = nums.begin(); it < nums.end() - 2; it++) {

            if (it != nums.begin() && *(it - 1) == *it) {
                continue;
            }

            auto l = it + 1;
            auto r = nums.end() - 1;

            while (l < r) {
                int distance = *it + *l + *r;

                if (distance < 0) {
                    l++;
                } else if (distance > 0) {
                    r--;
                } else if (distance == 0) {
                    out.push_back({*it, *l, *r});
                    do {
                        l++;
                    } while (*l == *(l - 1) && l < r);
                }

            }
        }

        return out;
    }
};