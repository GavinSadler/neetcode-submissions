class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0;
        int r = 0;

        unordered_map<char, int> chars;

        chars[s[r]]++;

        int maxString = 0;

        while (r < s.size()) {
            
            int mostFrequent = 0;
            int size = 0;
            
            for(auto it = chars.begin(); it != chars.end(); it++) {
                size += (*it).second;
                mostFrequent = max(mostFrequent, (*it).second);
            }


            if (k >= size - mostFrequent) {
                r++;
                chars[s[r]]++;
                maxString = max(maxString, r - l);
            } else {
                chars[s[l]]--;
                l++;
            }
        }

        return maxString;
    }
};