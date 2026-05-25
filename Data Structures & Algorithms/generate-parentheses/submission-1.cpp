class Solution {
    int numPairs;
    vector<string> out;
    string stack;

    void generate(int numOpen, int numClose) {
        if (numOpen == numClose && numClose == numPairs) {
            out.push_back(stack);
            return;
        }
        
        if (numOpen < numPairs) {
            stack.push_back('(');
            generate(numOpen + 1, numClose);
            stack.pop_back();
        }

        if (numClose < numOpen) {
            stack.push_back(')');
            generate(numOpen, numClose + 1);
            stack.pop_back();
        }
    }

public:
    vector<string> generateParenthesis(int n) {
        numPairs = n;

        stack = "";

        generate(0, 0);

        return out;
    }
};