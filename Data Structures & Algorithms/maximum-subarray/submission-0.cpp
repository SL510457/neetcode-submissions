class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        vector<int> prefix(n+1,0);
        for(int i = 1; i <= n; i++) {
            sum += nums[i-1];
            prefix[i] = sum;
        }
        
        int sol = INT_MIN;
        int curMin = prefix[0];

        for(int i = 0; i < n; i++) {
            sol = max(sol, prefix[i+1] - curMin);
            curMin = min(curMin,prefix[i+1]);
        }

        return sol;
    }
};
