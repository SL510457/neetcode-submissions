class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        int cost = 0;
        vector<bool> inMST(n,false);
        vector<int> minDist(n,INT_MAX);
        minDist[0] = 0;
        
        for(int s = 0; s < n; s++) {
            // find minDist
            int u = -1;
            for(int i = 0; i < n; i++) {
                if(!inMST[i] && (u==-1 || minDist[i] < minDist[u])) {
                    u = i;
                }
            }

            cost += minDist[u];
            inMST[u] = true;

            for(int i = 0; i < n; i++) {
                if(!inMST[i])
                    minDist[i] = min(minDist[i], abs(points[i][0]-points[u][0]) + abs(points[i][1]-points[u][1]));
            }
        }


        return cost;
    }
};
