class Solution {
public:
    vector<int> com;
    vector<vector<int>> sol;

    void backtrack(vector<int>& candidates, int start, int target) {
        if(target == 0) {
            sol.push_back(com);
            return;
        }    
        if(target < 0) 
            return;

        for(int i = start; i < (int)candidates.size(); i++) {
            if(i > start && candidates[i] == candidates[i-1])
                continue;

            com.push_back(candidates[i]);
                
            backtrack(candidates, i+1, target-candidates[i]);

            com.pop_back();
        }
        
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        
        backtrack(candidates, 0, target);

        return sol;
        
    }
};
