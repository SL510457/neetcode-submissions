class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int time = 0;
        int size = 0;
        
        queue<pair<int,int>> q;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 2) {
                    time = -1;
                    q.push({i,j});
                    size++;
                }
            }
        }

        while(q.size() > 0) {
            while(size > 0) {
                pair c = q.front();
                q.pop();
                
                if(c.first-1 > -1 && c.first-1 < n && grid[c.first-1][c.second] == 1) {
                    q.push({c.first-1, c.second});
                    grid[c.first-1][c.second] = 2;
                }
                if(c.first+1 > -1 && c.first+1 < n && grid[c.first+1][c.second] == 1) {
                    q.push({c.first+1, c.second});
                    grid[c.first+1][c.second] = 2;
                }  
                if(c.second-1 > -1 && c.second-1 < m && grid[c.first][c.second-1] == 1) {
                    q.push({c.first, c.second-1});
                    grid[c.first][c.second-1] = 2;
                } 
                if(c.second+1 > -1 && c.second+1 < m && grid[c.first][c.second+1] == 1) {
                    q.push({c.first, c.second+1});
                    grid[c.first][c.second+1] = 2;
                }  

                size--;
            }
            size = q.size();
            time++;
        }



        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1)
                    return -1;
            }
        }
        
        return time;
    }
};
