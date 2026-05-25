class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<
            pair<double, vector<int>*>,
            vector<pair<double, vector<int>*>>,
            greater<pair<double, vector<int>*>>
        > pq;
        
        for (auto& p : points) {
            int x = p[0];
            int y = p[1];

            double d = sqrt(x * x + y * y);

            pq.push({d, &p});
        }

        vector<vector<int>> out;

        for(int i = 0; i < k; i++) {
            auto e = pq.top();
            pq.pop();
            out.push_back(*(e.second));
        }

        return out;
    }
};
