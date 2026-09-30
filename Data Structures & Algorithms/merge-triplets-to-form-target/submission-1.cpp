class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        int n = triplets.size();
        vector<int> m(3,-1);
        for(int i = 0; i < n; i++) {
            if(triplets[i][0] <= target[0] && triplets[i][1] <= target[1] && triplets[i][2] <= target[2]) {
                m[0] = max(m[0], triplets[i][0]);
                m[1] = max(m[1], triplets[i][1]);
                m[2] = max(m[2], triplets[i][2]);
            }
        }
        if(m[0] != target[0] || m[1] != target[1] || m[2] != target[2])
        return false;
        
        return true;
        
    }
};
