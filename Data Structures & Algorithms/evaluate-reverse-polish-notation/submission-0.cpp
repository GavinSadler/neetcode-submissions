class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;

        for(const string& token : tokens) {
            char tokenChar = token[0];

            if (tokenChar >= '0' && tokenChar <= '9' || tokenChar == '-' && token.size() > 1) {
                s.push(stoi(token));
                continue;
            }

            int n1 = s.top();
            s.pop();
            int n2 = s.top();
            s.pop();

            if (tokenChar == '+') {
                s.push(n2 + n1);
            } else if (tokenChar == '-') {
                s.push(n2 - n1);
            } else if (tokenChar == '*') {
                s.push(n2 * n1);
            } else if (tokenChar == '/') {
                s.push(n2 / n1);
            }
        }

        return s.top();
    }
};