class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,int>> pq;
        int n = points.size();

        for(int i = 0; i < n; i++) {
            int d = pow(points[i][0],2) + pow(points[i][1],2);
            cout << d << endl;
            pq.push({d,i});
            while(pq.size() > k) {
                pq.pop();
            }
        }

        int kC = pq.top().first;
        vector<vector<int>> sol;
        while(!pq.empty()) {
            sol.push_back(points[pq.top().second]);
            pq.pop();
        }
        return sol;
    }
};
