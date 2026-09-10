class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int,int> num;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            if(num.find(nums[i]) == num.end()) {
                num[nums[i]] = 1;
            }
            else {
                return true;
            }
        }
        return false;
    }
};