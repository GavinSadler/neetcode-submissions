
struct KeyHash {
    size_t operator()(const array<int, 26>& k) const {
        size_t hash = 0;
        for (int i : k) {
            hash ^= std::hash<int>()(i);
        }
        return hash;
    }
};

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        unordered_map<array<int, 26>, vector<string>, KeyHash> m;

        for(string word : strs) {
            array<int, 26> chars = {0};

            for (char c : word) {
                chars[c - 'a']++;
            }

            m[chars].push_back(word);
        }
        
        vector<vector<string>> out;

        for (const auto& v : m) {
            out.push_back(v.second);
        }

        return out;
    }
};
