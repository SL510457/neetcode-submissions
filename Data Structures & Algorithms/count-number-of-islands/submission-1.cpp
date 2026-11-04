class Solution {
public:
    void dfs(vector<vector<char>>& grid, int r, int c) {
        if(r > -1 && r < (int)grid.size() && c > -1 && c < (int)grid[0].size() && grid[r][c] == '1') {
         grid[r][c] = 0;
         dfs(grid, r-1, c);   
         dfs(grid, r+1, c);   
         dfs(grid, r, c-1);   
         dfs(grid, r, c+1);   
        }
        else
            return;
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == '1') {
                    cnt++;
                    dfs(grid,i,j);
                }
            }
        }

        return cnt;
    }
};
