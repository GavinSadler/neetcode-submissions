class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = *max_element(piles.begin(), piles.end());
        
        int out = r;

        while (l <= r) {
            int m = l + (r - l) / 2;

            long long t = 0;

            for(const auto& p : piles) {
                // t += (p + m - 1) / m;
                t += ceil((double) p / m);
            }

            if (t <= h) {
                r = m - 1;
                out = m;
            } else {
                l = m + 1;
            }
        }

        return out;
    }
};