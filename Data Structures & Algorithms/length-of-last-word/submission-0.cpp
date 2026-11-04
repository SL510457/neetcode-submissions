class Solution {
public:
    int lengthOfLastWord(string s) {
        int cnt = 0;
        int lcnt = 0;
        int n = s.size();
        for(int i = 0; i < n; i++) {
            if(s[i] == ' ') 
                cnt = 0;
            else {
                cnt++;
                lcnt = cnt;
            }
        }

        return lcnt;
    }
};