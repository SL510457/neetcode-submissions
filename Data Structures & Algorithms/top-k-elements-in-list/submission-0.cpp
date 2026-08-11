class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int count[2001]={0};
        int n = nums.size();
        vector<int> sol;
        for(int i = 0; i < n; i++) {
            count[nums[i]+1000]++;
        }
        for(int i = 0; i < k; i++) {
            int m = INT_MIN;
            int cur;
            for(int j = 0; j < 2001; j++) {
                if(count[j] > m) {
                    cur = j-1000;
                    m = count[j];
                }   
            }
            
            sol.push_back(cur);
            count[cur+1000] = 0;
        }

        return sol;
    }
};
