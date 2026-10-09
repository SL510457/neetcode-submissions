class Solution {
public:
    vector<int> com;
    vector<vector<int>> sol;

    void backtrack(vector<int>& candidates, unordered_map<int,int>& um, int start, int target) {
        if(target == 0) {
            sol.push_back(com);
            return;
        }    
        if(target < 0) 
            return;

        for(int i = start; i < (int)candidates.size(); i++) {
            if(um[candidates[i]] > 0) {
                com.push_back(candidates[i]);
                um[candidates[i]]--;
                
                backtrack(candidates, um, i, target-candidates[i]);

                com.pop_back();
                um[candidates[i]]++;
            }
        }
        
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        unordered_map<int,int> um;
        for(int i = 0; i < (int)candidates.size(); i++) {
            um[candidates[i]]++;
        }

        candidates.erase(unique(candidates.begin(), candidates.end()), candidates.end());
        
        backtrack(candidates, um, 0, target);

        return sol;
        
    }
};
