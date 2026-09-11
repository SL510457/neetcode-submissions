class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> nums2 = nums;
        vector<vector<int>> dp;
        for(int i = 0; i < n+1; i++) {
            vector<int> vec(n+1,0);
            dp.push_back(vec);
        }
        
        sort(nums2.begin(), nums2.end());
        nums2.erase(unique(nums2.begin(), nums2.end()), nums2.end());
        int m = nums2.size();
        
        for(int i = 1; i < n+1; i++) {
            for(int j = 1; j < m+1; j++) {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                if(nums[i-1] == nums2[j-1]) {
                    dp[i][j] = max(dp[i][j], dp[i-1][j-1]+1);
                }
            }
        }
        //   [9,1,4,2,3,3,7]
        // 1  0 1 1 1 1 1 1
        // 2  0 1 1 2 2 2 2
        // 3  0 1 1 2 3 3 3
        // 3  0 1 1 2 3 4
        // 4
        // 7
        // 9

        return dp[n][m];

    }
};
