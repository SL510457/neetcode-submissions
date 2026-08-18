class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        int product = 1, countZero = 0;
        for(int i = 0; i < n; i++) {
            if(nums[i] != 0)
                product *= nums[i];
            else {
                countZero++;
            }
        }

        vector<int> sol;
        
        if(!countZero)
            for(int i = 0; i < n; i++) {
                sol.push_back(product/nums[i]);
            }
        else if(countZero == 1) {
            for(int i = 0; i < n; i++) {
                if(!nums[i])
                    sol.push_back(product);
                else
                    sol.push_back(0);
            }
        }
        else {
            for(int i = 0; i < n; i++)
                sol.push_back(0);
        }

        return sol;
    }
};
