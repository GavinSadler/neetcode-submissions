class Solution {
public:
    bool alphaNum(char c) {
        return (c >= 'A' && c <= 'Z' || 
                c >= 'a' && c <= 'z' || 
                c >= '0' && c <= '9');
    }

    bool isPalindrome(string s) {
        int begin = 0;
        int end = s.size() - 1;

        while (begin < end) {
            while (begin < end && !alphaNum(s[begin])) {
                begin++;
            }
            
            while (end > begin && !alphaNum(s[end])) {
                end--;
            }
            
            if (tolower(s[begin]) != tolower(s[end])) {
                return false;
            }

            begin++;
            end--;
        }
        return true;
    }
};