class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount+1,0);
        dp[0] = 1;
        int n = coins.size();
        for(int c = 0; c < n; c++) {
            for(int a = coins[c]; a < amount+1; a++) {
                dp[a] = dp[a] + dp[a-coins[c]];
            }
        }

        return dp[amount];
    }
};
