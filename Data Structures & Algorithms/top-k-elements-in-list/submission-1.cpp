class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> f;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            if(f.find(nums[i])  == f.end()) {
                f[nums[i]] = 1;
            }
            else
                f[nums[i]]++;
        }
        
        priority_queue<pair<int,int>> pq;
        for(const auto& i: f) {
            pq.push({i.second,i.first});
        }
        vector<int> sol;
        for(int i = 0; i < k; i++) {
            int cur = pq.top().second;
            sol.push_back(cur);
            pq.pop();
        }

        return sol;
    }
};
