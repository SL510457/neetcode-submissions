class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> sol(n+1,0);

        for(int i = 1; i < n+1; i++) {
            sol[i] = sol[i & i-1] + 1;
        }

        return sol;
    }
};
