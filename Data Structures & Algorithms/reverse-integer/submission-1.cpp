class Solution {
public:
    int reverse(int x) {
        vector<int> b;
        while(x != 0) {
            b.push_back(x%10);
            x /= 10;
        }

        int sol = 0;
        for(int i = 0; i < (int)b.size(); i++) {
            if(sol > INT_MAX/10 || (sol == INT_MAX/10 && b[i] > 7))
                return 0;
            if(sol < INT_MIN/10 || (sol == INT_MIN/10 && b[i] < -8))
                return 0;
            
            sol *= 10;
            sol += b[i];
        }

        return sol;
    }
};
