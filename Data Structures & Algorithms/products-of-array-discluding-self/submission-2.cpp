class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> p(n,0), s(n,0), sol(n,0);
        p[0] = nums[0];
        s[n-1] = nums[n-1];
        for(int i = 1; i < n; i++) {
            p[i] = p[i-1] * nums[i];
            s[n-i-1] = s[n-i] * nums[n-i-1];
        }
        // for(int i = 0; i < n; i++) {
        //     cout << p[i] << " ";
        // }
        // cout << endl;

        // for(int i = 0; i < n; i++) {
        //     cout << s[i] << " ";
        // }
        // cout << endl;
        
        

        for(int i = 0; i < n; i++) {
            int pre = 1, suf = 1;
            if(i-1 > -1)
                pre = p[i-1];
            if(i+1 < n)
                suf = s[i+1];
            sol[i] = pre*suf;
        }

        return sol;
    //     0  1  2  3
    //     1  2  4  6
    //     ----------
    //     1  2  8 48
    //    48 48 24  6   
    //    48 24 12  8
        // n = 4
    }
};
