class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        long long cnt = 0;
        sort(intervals.begin(), intervals.end());
        int end = intervals[0][1];

        for(int i = 1; i < n; i++) {
            if(intervals[i][0] < end) {
                if(intervals[i][1] < end) {
                    end = intervals[i][1];
                }

                cnt++;
            }
            else {
                end = intervals[i][1];
            }
        }

        return cnt;
    }
};
