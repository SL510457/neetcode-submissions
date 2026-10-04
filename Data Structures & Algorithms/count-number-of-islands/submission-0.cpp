class Solution {
public:
    void dfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int r, int c, int n, int m) {
        if(r < 0 || c < 0 || r > n-1 || c > m-1)
            return;
        
        if(visited[r][c] || grid[r][c] == '0')
            return;

        visited[r][c] = true;

        dfs(grid, visited, r-1, c, n, m);
        dfs(grid, visited, r+1, c, n, m);
        dfs(grid, visited, r, c-1, n, m);
        dfs(grid, visited, r, c+1, n, m);

    }
    int numIslands(vector<vector<char>>& grid) {
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(),false));
        int n = grid.size();
        int m = grid[0].size();
        int cnt = 0;
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == '1' && visited[i][j] == 0) {
                        cnt++;
                        dfs(grid, visited, i, j, n, m);
                }
            }
        }

        return cnt;
    }
};
