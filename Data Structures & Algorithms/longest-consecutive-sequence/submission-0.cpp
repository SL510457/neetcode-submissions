class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> us;
        
        for(int i = 0; i < n; i++) {
            if(us.find(nums[i]) == us.end())
                us.insert(nums[i]);
        }
        // 2,20,4,10,3,4,5
        // 2,3,4,4,5,10,20
        int longsum = 0;
        for(int i = 0; i < n; i++) {
            if(us.find(nums[i]-1) == us.end()) {
                int s = 1;
                for(int j = 1; j < n; j++) {
                    if(us.find(nums[i]+j) != us.end())
                        s++;
                    else
                        break;
                }
                longsum = max(longsum, s);
            }
        }
        return longsum;
    }
};
