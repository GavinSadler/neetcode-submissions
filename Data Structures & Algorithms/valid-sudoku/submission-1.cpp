class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        set<char> charset;

        for(int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                char c = board[i][j];

                if (charset.find(c) != charset.end()) {
                    return false;
                }

                if (c != '.') {
                    charset.insert(c);
                }
            }

            charset.clear();
        }

        // cout << "Rows are good\n";

        for(int j = 0; j < 9; j++) {
            for (int i = 0; i < 9; i++) {
                char c = board[i][j];

                if (charset.find(c) != charset.end()) {
                    return false;
                }

                if (c != '.') {
                    charset.insert(c);
                }
            }

            charset.clear();
        }
        
        // cout << "Columns are good\n";

        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    for (int l = 0; l < 3; l++) {
                        char c = board[i * 3 + k][j * 3 + l];

                        if (charset.find(c) != charset.end()) {
                            return false;
                        }

                        if (c != '.') {
                            charset.insert(c);
                        }
                    }
                }
                charset.clear();
            }
        } 

        return true;
    }
};