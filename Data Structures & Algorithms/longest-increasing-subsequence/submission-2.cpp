class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> tails;
        tails.push_back(nums[0]);
        
        for(int i = 1; i < n; i++) {
            int l = 0, r = tails.size();
            while(l < r) {
                int m = l + (r-l)/2;
                if(tails[m] >= nums[i])
                    r = m;
                else 
                    l = m+1;
            }
            if(l == tails.size())
                tails.push_back(nums[i]);
            else
                tails[l] = nums[i];
        }

        return tails.size();
    }
};
