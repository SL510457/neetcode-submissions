class Solution {
public:
    vector<int> com;
    vector<vector<int>> sol;
    void backtrack(vector<int>& nums, vector<bool>& used) {
        if((int)com.size() == (int)nums.size()) {
            sol.push_back(com);
            return;
        }


        for(int i = 0; i < (int)nums.size(); i++) {
            if(used[i])
                continue;

            com.push_back(nums[i]);
            used[i] = true;

            backtrack(nums, used);

            com.pop_back();
            used[i] = false;  
        }
        
    }

    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<bool> used(n,false);
        backtrack(nums, used);
        return sol;
    }
};
