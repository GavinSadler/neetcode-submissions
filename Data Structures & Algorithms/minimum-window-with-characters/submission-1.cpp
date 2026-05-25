class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> signature;

        for(const char& c : t) {
            signature[c]++;
        }

        int l_min = -1;
        int r_min = -1;

        unordered_map<char, int> window;

        int have = 0;
        int need = signature.size();

        int l = 0;
        int r = 0;

        for(r = 0; r < s.size(); r++) {

            char c = s[r];
            window[s[r]]++;

            if (signature.find(c) != signature.end() && signature[c] == window[c]) {
                have++;
            }

            while (have == need) {
                if (r - l < r_min - l_min || l_min == -1) {
                    r_min = r;
                    l_min = l;
                }

                char cl = s[l];

                window[cl]--;
                
                if (signature.find(cl) != signature.end() && window[cl] < signature[cl]) {
                    have--;
                }

                l++;
            }
        }

        if (l_min == -1)
            return "";

        return s.substr(l_min, max(r_min - l_min + 1, 1));
    }
};