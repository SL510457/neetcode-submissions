class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        int sol = nums[0];
        for(int i = 1 ; i < n; i++) {
            sol ^= nums[i];
        }

        return sol;
    }
};
