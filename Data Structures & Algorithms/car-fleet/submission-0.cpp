class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> cars;

        for(int i = 0; i < position.size(); i++) {
            cars.push_back({position[i], speed[i]});
        }

        sort(cars.rbegin(), cars.rend());

        vector<double> s;

        for(const auto& p : cars) {
            s.push_back((double) (target - p.first) / p.second);
            
            if (s.size() >= 2 && s.back() <= s[s.size() - 2]) {
                s.pop_back();
            }
        }

        return s.size();
    }
};