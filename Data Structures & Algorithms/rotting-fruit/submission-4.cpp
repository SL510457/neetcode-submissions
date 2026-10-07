class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m,false));
        queue<pair<int,int>> q;
        int cnt = 0; //count banana 1 
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 2) {
                    q.push({i,j});
                    visited[i][j] = true;
                }
                if(grid[i][j] == 1)
                    cnt++;
            }
        }
        
        int size = q.size();
        int time = 0;

        while(!q.empty() && cnt > 0) {
            while(size > 0) {
                auto [r,c] = q.front();
                q.pop();

                if(r-1 >= 0 && grid[r-1][c] == 1 && !visited[r-1][c]) {q.push({r-1,c}); visited[r-1][c] = true; cnt--;} 
                if(r+1 < n && grid[r+1][c] == 1 &&  !visited[r+1][c]) {q.push({r+1,c}); visited[r+1][c] = true; cnt--;} 
                if(c-1 >= 0 && grid[r][c-1] == 1 &&  !visited[r][c-1]) {q.push({r,c-1}); visited[r][c-1] = true; cnt--;} 
                if(c+1 < m && grid[r][c+1] == 1 &&  !visited[r][c+1]) {q.push({r,c+1}); visited[r][c+1] = true; cnt--;}

                size--;
            }
            
            time++;
            size = q.size();
        }

        if(cnt > 0)
            return -1;
        else
            return time;
            


        
    }
};
