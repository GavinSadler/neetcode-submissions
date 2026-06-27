class Solution {
    vector<int> memo;

    int dp(int i, int j, string& str1, string& str2) {
        if (i == str1.size() || j == str2.size())
            return 0;
        
        if (memo[j * str1.size() + i] != -1)
            return memo[j * str1.size() + i];
        
        int x = (str1[i] == str2[j]) + dp(i + 1, j + 1, str1, str2);
        int y = dp(i + 1, j, str1, str2);
        int z = dp(i, j + 1, str1, str2);

        memo[j * str1.size() + i] = max(x, max(y, z));

        return memo[j * str1.size() + i];
    }

    //   a b c d
    // a
    // b
    // c       1
    // d 1 1 1 1

public:
    int longestCommonSubsequence(string text1, string text2) {
        memo = vector(text1.size() * text2.size(), -1);
        return dp(0, 0, text1, text2);
    }
};
