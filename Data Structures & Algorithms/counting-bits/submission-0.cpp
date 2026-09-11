class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> sol;
        uint32_t nn = (uint32_t)n;
        for(uint32_t i = 0; i <= nn; i++) {
            sol.push_back(popcount(i));
        }

        return sol;
    }
};
