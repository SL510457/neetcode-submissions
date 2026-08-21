class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> prefix(n,0);
        int maxP = prices[n-1];
        prefix[n-1] = prices[n-1];
        for(int i = n-2; i > -1; i--) {
            maxP = max(maxP, prices[i]);
            prefix[i] = maxP;
        }

        int sol = 0;
        for(int i = 0; i < n; i++) {
            // cout << "prefix[i]: " << prefix[i] << "prices[i]: " << prices[i] << endl;
            sol = max(sol, prefix[i] - prices[i]);
        }

        return sol;
    }
};