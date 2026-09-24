class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int n = intervals.size();
        vector<vector<int>> sol;
        sol.push_back(intervals[0]);
        int end = intervals[0][1];

        for(int i = 1; i < n; i++) {
            if(intervals[i][0] <= end) {
                end = max(end, intervals[i][1]);
                sol[sol.size()-1][1] = end;
            }
            else {
                sol.push_back(intervals[i]);
                end = intervals[i][1];
            }
        }

        return sol;
    }
};
