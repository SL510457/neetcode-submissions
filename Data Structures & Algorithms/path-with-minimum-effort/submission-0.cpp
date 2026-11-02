class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int r = heights.size(), c = heights[0].size();
        
        vector<vector<int>> dist(r,vector<int>(c,INT_MAX));
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq; 

        dist[0][0] = 0;
        pq.push({0,{0,0}});

        while(!pq.empty()) {
            auto [d,u] = pq.top();
            auto [row,col] = u;
            pq.pop();

            if(d > dist[row][col])
                continue;

            if(row+1 < r) {
                int diff = max(d,abs(heights[row+1][col] - heights[row][col]));
                if(diff < dist[row+1][col]) {
                    pq.push({diff,{row+1,col}});
                    dist[row+1][col] = diff;
                }
            }  
            if(row-1 > -1) {
                int diff = max(d,abs(heights[row-1][col] - heights[row][col]));
                if(diff < dist[row-1][col]) {
                    pq.push({diff,{row-1,col}});
                    dist[row-1][col] = diff;
                }
            }
            if(col+1 < c) {
                int diff = max(d,abs(heights[row][col+1] - heights[row][col]));
                if(diff < dist[row][col+1]) {
                    pq.push({diff,{row,col+1}});
                    dist[row][col+1] = diff;
                }
            }
            if(col-1 > -1) {
                int diff = max(d,abs(heights[row][col-1] - heights[row][col]));
                if(diff < dist[row][col-1]) {
                    pq.push({diff,{row,col-1}});
                    dist[row][col-1] = diff;
                }
            }
        }

        return dist[r-1][c-1];

    }
};