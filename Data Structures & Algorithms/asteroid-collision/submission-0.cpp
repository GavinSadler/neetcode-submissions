class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        
        stack<pair<int, int>> sPos;
        stack<pair<int, int>> sNeg;

        for(int i = 0; i < asteroids.size(); i++) {
            int aLeft = asteroids[i];
            
            if (aLeft > 0) {
                sPos.push({i, aLeft});
            } else {
                while (!sPos.empty() && abs(aLeft) >= sPos.top().second) {
                    if (abs(aLeft) == sPos.top().second) {
                        sPos.pop();
                        break;
                    }

                    sPos.pop();
                }
            }
            
            int aRight = asteroids[asteroids.size() - 1 - i];

            if (aRight < 0) {
                sNeg.push({asteroids.size() - 1 - i, aRight});
            } else {
                while (!sNeg.empty() && aRight >= abs(sNeg.top().second)) {
                    if (aRight == abs(sNeg.top().second)) {
                        sNeg.pop();
                        break;
                    }

                    sNeg.pop();
                }
            }
        }

        vector<pair<int, int>> s;

        while (!sPos.empty()){
            s.push_back(sPos.top());
            sPos.pop();
        }
        
        while (!sNeg.empty()){
            s.push_back(sNeg.top());
            sNeg.pop();
        }

        sort(s.begin(), s.end());

        vector<int> out;

        for(auto &x: s)
            out.push_back(x.second);

        return out;
    }
};