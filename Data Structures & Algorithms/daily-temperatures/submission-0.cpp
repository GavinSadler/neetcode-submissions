class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        
        vector<int> out(n, 0);
        stack<int> s;

        for(int i = 0; i < n; i++) {
            int nextTemp = temperatures[i];
            
            while(!s.empty() && nextTemp > temperatures[s.top()]) {
                out[s.top()] = i - s.top();
                s.pop();
            }

            s.push(i);
        }

        while(!s.empty()) {
            out[s.top()] = 0;
            s.pop();
        }

        return out;
    }
};