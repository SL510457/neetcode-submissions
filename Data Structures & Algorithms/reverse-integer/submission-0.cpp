class Solution {
public:
    int reverse(int x) {
        vector<int> b;
        while(x != 0) {
            b.push_back(x%10);
            cout << x%10 << endl;
            x /= 10;
        }
        // 4321
        long long sol = 0;
        for(int i = 0; i < (int)b.size(); i++) {
            if(sol*10 + b[i] > INT_MAX || sol*10 + b[i] < INT_MIN)
            return 0;
            
            sol *= 10;
            sol += b[i];
        }


        return sol;
    }
};
