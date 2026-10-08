class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n+1, vector<int>(amount+1,amount+1));
        for(int i = 0; i < n+1; i++)
            dp[i][0] = 0;
        
        for(int i = 1; i < n+1; i++) {
            for(int j = 1; j < amount+1; j++) {
                if(coins[i-1] > j) {
                    dp[i][j] = dp[i-1][j];
                }
                else {
                    dp[i][j] = min(dp[i-1][j], dp[i][j-coins[i-1]]+1);
                }
            }
        }

        if(dp[n][amount] > amount)
            return -1;

        return dp[n][amount];
        
        //    0 1 2 3 4 5 6 7 8 9 10 11 12
        // 0  0 x x x x x x x x x  x  x  x
        // 1  0 1 2 3 4 5 6 7 8 9 10 11 12
        // 5  0 
        // 10 0


    }
};
