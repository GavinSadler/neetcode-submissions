class Solution {
public:

    string encode(vector<string>& strs) {
        string out;

        for(const string& s : strs) {
            out += to_string(s.size()) + '#' + s;
        }

        return out;
    }

    vector<string> decode(string s) {
        if (s.size() == 0) return {};

        cout << s << "\n";
        
        vector<string> out;
        
        for (int i = 0; i < s.size(); i++) {
            string num;

            while (s[i] != '#') {
                num += s[i];
                cout << num << "\n";
                i++;
            }

            int num_size = std::stoi(num);

            string new_str;

            for(int j = 0; j < num_size; j++) {
                new_str += s[i + j + 1];
            }

            i += new_str.size();

            out.push_back(new_str);
        }

        return out;
    }
};
