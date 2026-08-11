class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int numOfstrs = strs.size();
        vector<string> strs2 = strs;

        vector<vector<string>> sol;
        vector<int> tag(numOfstrs,0);
        int numOfgroups = 0;
        unordered_map<string,int> group;
        
        for(int i = 0; i < numOfstrs; i++) {
            sort(strs2[i].begin(), strs2[i].end());
            if(group.find(strs2[i]) == group.end()) {
                group[strs2[i]] = numOfgroups;
                numOfgroups++;
                vector<string> add;
                add.push_back(strs[i]);
                sol.push_back(add);
            }
            else {
                sol[group[strs2[i]]].push_back(strs[i]);
            }

        }
        
        return sol;
    }
};
