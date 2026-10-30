class Solution {
public:
    pair<int,int> expend(int l, int r, string& s) {
        while(l > -1 && r < (int)s.size() && s[l] == s[r]) {
            l--;
            r++;
        }
        
        return {l+1,r-1};
    }

    string longestPalindrome(string s) {
        int n = s.size();
        int maxL = 0;
        int start = 0;
        for(int i = 0; i < n; i++) {
            pair<int,int> l1 = expend(i,i,s);
            if(i != n-1) {
                pair<int,int> l2 = expend(i,i+1,s);
                if(l2.second-l2.first+1 > maxL) {
                    maxL = l2.second-l2.first+1;
                    start = l2.first;
                }
            }

            if(l1.second-l1.first+1 > maxL) {
                    maxL = l1.second-l1.first+1;
                    start = l1.first;
            }
        }

        return s.substr(start,maxL);
        
    }
};
