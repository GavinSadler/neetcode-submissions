class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> s(stones.begin(), stones.end());

        while(s.size() >= 2) {
            int x = s.top();
            s.pop();
            int y = s.top();
            s.pop();

            if (x < y) {
                s.push(y - x);
            } else if (y < x) {
                s.push(x - y);
            }
        }

        if (s.size() == 1) {
            return s.top();
        }

        return 0;
    }
};
