class Solution {
public:
    int trap(vector<int>& height) {
        
        int w = 0;

        auto l = height.begin(), r = height.end() - 1;

        int mh = min(*l, *r);

        while (l < r) {
            mh = max(mh, min(*l, *r));

            if (*l < *r) {
                w += max(0, mh - *l);
                l++;
            } else {
                w += max(0, mh - *r);
                r--;
            }
        }

        return w;
    }
};
