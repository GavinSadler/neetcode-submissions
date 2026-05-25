class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0) return 0;

        unordered_set<int> s(nums.begin(), nums.end());

        int currentConsecutive = 1;
        int largestConsecutive = 1;

        for(auto it = s.begin(); it != s.end(); it++) {
            int currentNum = *it;

            if (s.find(currentNum - 1) != s.end()) {
                continue;
            }

            while (s.find(currentNum + 1) != s.end()) {
                currentNum++;
                currentConsecutive++;

                if (largestConsecutive < currentConsecutive) {
                    largestConsecutive = currentConsecutive;
                }
            }

            currentConsecutive = 1;
        }

        return largestConsecutive;
    }
};