class Solution {
public:
    vector<int> path;
    vector<vector<int>> sol;

    void backtrack(vector<int>& nums, int start) {
        sol.push_back(path);
        
        for(int i = start; i < (int)nums.size(); i++) {
            path.push_back(nums[i]);
            
            backtrack(nums, i+1);

            path.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        backtrack(nums,0);
        
        return sol;
         
    }
};