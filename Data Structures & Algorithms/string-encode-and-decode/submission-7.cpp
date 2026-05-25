class Solution {
public:

    string encode(vector<string>& strs) {
        string out;

        for(const string& s : strs) {
            out += s;
            out += "_^";
        }

        return out;
    }

    vector<string> decode(string s) {
        if (s.size() == 0) return {};
        vector<string> out;
        
        string temp = "";

        for (int i = 0; i < s.size() - 1; i++) {
            char char1 = s[i];
            char char2 = s[i + 1];

            if (char1 == '_' && char2 == '^') {
                out.push_back(temp);
                temp = "";
                i++;
            } else {
                temp += s[i];
            }
        }

        // out.push_back(temp);

        return out;
    }
};
