class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<int,int> lastIndex;
        int n = s.size();
        vector<int> sol;
        
        for(int i = 0; i < n; i++) {
            lastIndex[s[i]] = i;
        }
        
        int l = 0, r = 0;
        for(int i = 0; i < n; i++) {
            if(i > r) {
                sol.push_back(r-l+1);
                l = i;
                r = lastIndex[s[i]];
            } 
            else {
                r = max(r,lastIndex[s[i]]);
            }
        }
        sol.push_back(r-l+1);
        
        return sol;
        
    }
};
