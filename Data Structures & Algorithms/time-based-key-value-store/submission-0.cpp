class TimeMap {
    map<string, vector<pair<int, string>>> m;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        m[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        vector<pair<int, string>>& values = m[key];

        // if (values.size() == 1) { return values[0].second; }

        int l = 0;
        int r = values.size() - 1;

        while (l <= r) {
            int m = l + (r - l) / 2;

            if (values[m].first == timestamp) {
                return values[m].second;
            }

            if (values[m].first < timestamp) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }

        if (r < 0) {
            return "";
        }

        return values[r].second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */