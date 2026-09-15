class Solution {
public:
    int n;
    int m;
    void z(vector<vector<char>>& board, int i, int j) {
        if(i < 0 || i > n-1 || j < 0 || j > m-1 || board[i][j] != 'O' )
            return;

        if(board[i][j] == 'O')
            board[i][j] = '#';
        
        z(board, i-1,j);
        z(board, i+1,j);
        z(board, i,j-1);
        z(board, i,j+1);

    }
    void solve(vector<vector<char>>& board) {
        n = board.size();
        m = board[0].size();

        for(int i = 0; i < n; i++) {
            if(board[i][0] == 'O') {
                z(board, i,0);
            }
            if(board[i][m-1] == 'O') {
                z(board, i,m-1);
            }
        }

        for(int j = 0; j < m; j++) {
            if(board[0][j] == 'O') {
                z(board, 0,j);
            }
            if(board[n-1][j] == 'O') {
                z(board, n-1,j);
            }
        }

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(board[i][j] == 'O')
                    board[i][j] = 'X';
                else if(board[i][j] == '#')
                    board[i][j] = 'O';
            }
        }
        
    }
};
