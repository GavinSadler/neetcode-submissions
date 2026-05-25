class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l = 0;
        int r = 1;

        int maxProfit = 0;

        while(l < prices.size() - 1) {
            int profit = prices[r] - prices[l];

            maxProfit = max(maxProfit, profit);

            if (r == prices.size() - 1) {
                l++;
            } else if (profit < 0) {
                l++;
                r++;
            } else {
                r++;
            }
        }

        return maxProfit;
    }
};
