class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int l = 0;
        int r = 0;

        unordered_set<char> chars;

        int maxSubstring = 0;

        while (r < s.size()) {

            while (chars.find(s[r]) != chars.end()) {
                maxSubstring = max(maxSubstring, r - l);
                chars.erase(s[l]);
                l++;
            }

            chars.insert(s[r]);
            r++;
        }

        maxSubstring = max(maxSubstring, r - l);

        return maxSubstring;
    }
};