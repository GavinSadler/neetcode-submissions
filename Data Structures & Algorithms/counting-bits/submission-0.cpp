class Solution {
public:
    vector<int> countBits(int n) {
        
        // 10^5 = 100 * 100 * 10 = 100_000
        // 0_0000_0000_0000_0000

        vector<int> ans(n + 1, 0);

        int x = 0;
        int b = 1;

        // [0, b) calculated
        while (b <= n) {

            // Generate [b, 2b) or [b, n) from [0, b)
            while (x < b && x + b <= n) {
                ans[x + b] = ans[x] + 1;
                x += 1;
            }

            x = 0 ; // reset x
            b <<= 1; // b = 2b

        }

        return ans;
    }
};