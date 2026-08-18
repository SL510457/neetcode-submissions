class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i = 0; i < 9; i++) {
            int row[10] = {0}, column[10] = {0};
            for(int j = 0; j < 9; j++) {
                if(board[i][j] != '.') {
                    // cout << i << " " << j << endl;
                    if(row[board[i][j]-'0']) {
                        //  cout << "row[board[i][j]-'0': " << row[board[i][j]-'0'] << endl;
                        return false;
                    }
                    else 
                        row[board[i][j]-'0']++;
                }
                if(board[j][i] != '.') {
                    if(column[board[j][i]-'0'])
                        return false;
                    else 
                        column[board[j][i]-'0']++;
                }
            }
        }

        for(int i = 0; i < 9; i = i+3) {
            for(int j = 0; j < 9; j = j+3) {
                int box[10] = {0};
                for(int t = i; t < i+3; t++) {
                    for(int s = j; s < j+3; s++) {
                        if(board[t][s] != '.') {
                    if(box[board[t][s]-'0']) {
                        return false;
                    }
                    else 
                        box[board[t][s]-'0']++;
                }
                    }
                }
            }
        }

        return true;
    }
};
