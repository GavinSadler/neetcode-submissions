class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s2.size() < s1.size()) return false;

        int s1Sig[26] = { 0 };

        for(int i = 0; i < s1.size(); i++) {
            s1Sig[s1[i] - 'a']++;
        }

        int s2Sig[26] = { 0 };

        int l = 0;

        for(int r = 0; r < s2.size(); r++) {
            s2Sig[s2[r] - 'a']++;

            if (r - l >= s1.size()) {
                s2Sig[s2[l] - 'a']--;
                l++;
            }

            bool isPermutation = true;

            for(int i = 0; i < 26; i++) {
                if (s1Sig[i] != s2Sig[i]) {
                    isPermutation = false;
                    break;
                }
            }

            if (isPermutation) {
                return true;
            }
        }

        return false;
    }
};