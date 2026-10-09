class Solution {
public:
    vector<int> com;
    vector<vector<int>> sol;

    void backtrack(vector<int>& nums, int start, int target) {
        int sum = 0;
        for(int i = 0; i < (int)com.size(); i++) {
            sum += com[i];
        }
        if(sum == target) {
            sol.push_back(com);
        }
        if(sum >= target)
            return;
        
        for(int i = start; i < (int)nums.size(); i++) {
            com.push_back(nums[i]);
            backtrack(nums, i, target);
            com.pop_back();
        }

    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        backtrack(nums, 0, target);

        return sol;
    }
};
