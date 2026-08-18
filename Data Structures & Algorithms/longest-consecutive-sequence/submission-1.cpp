class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> us;
        
        for(int i = 0; i < n; i++) {
            if(us.find(nums[i]) == us.end())
                us.insert(nums[i]);
        }
        int longsum = 0;
        for(int num : us) {
            if(us.find(num-1) == us.end()) {
                int s = 1;
                while(us.find(num+s) != us.end()) {
                    s++;
                }
                longsum = max(longsum, s);
            }
        }
        
        return longsum;
    }
};
