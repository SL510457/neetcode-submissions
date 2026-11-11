class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) {
        kth = k;
        for(int i = 0; i < (int)nums.size(); i++) {
            min_pq.push(nums[i]);
        }
        while((int)min_pq.size() > kth) {
            max_pq.push(min_pq.top());
            min_pq.pop();
        }
    }
    
    int add(int val) {
        min_pq.push(val);
        if((int)min_pq.size() > kth) {
            max_pq.push(min_pq.top());
            min_pq.pop();
        }
        return min_pq.top();
    }
    
    priority_queue<int> max_pq; 
    priority_queue<int, vector<int>, greater<>> min_pq; 
    int kth;
};
