class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector<vector<int>> sol;
        for(int i = 0; i < n-2; i++) {
            if(i > 0 && nums[i] == nums[i-1])
                continue;
            else {
                int j = i+1, t = n-1;
                while(j < t) {
                    int nt = nums[t];
                    int nj = nums[j];
                    int ni = nums[i]*(-1);
                    if(nums[j] + nums[t] > ni) {
                        while(t > j && nums[t] == nt)
                            t--;
                    }
                    else if(nums[j] + nums[t] < ni) {
                        while(j < t && nums[j]==nj)
                            j++;
                    }
                    else {
                        vector<int> tri;
                        tri.push_back(nums[i]);
                        tri.push_back(nums[j]);
                        tri.push_back(nums[t]);
                        sol.push_back(tri);

                        while(t > i && nums[t] == nt)
                            t--;
                        while(j < n && nums[j]== nj)
                            j++;
                    }
                }
            }
        }

        return sol;
    }
};
