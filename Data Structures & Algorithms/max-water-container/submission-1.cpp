class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        int left = 0, right = n-1;
        int maxSum = 0;
        
        while(left < right) {
            int curSum = (right - left) * min(heights[left], heights[right]);
            maxSum = max(maxSum, curSum);
            if(heights[left] < heights[right])
                left++;
            else
                right--;
        }

        return maxSum;
    }
};
