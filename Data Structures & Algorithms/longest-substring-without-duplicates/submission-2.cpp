class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int l = 0, r = 0;
        int m = 0;
        unordered_map<char,int> um;
        
        while(r < n) {
            if(um.find(s[r]) != um.end() && um[s[r]] == 1) {
                while(l < r) {
                    if(s[l] == s[r]) {
                        l++;
                        break;
                    }
                    else {
                        um[s[l]] = 0;
                        l++;
                    }
                }
            }
            else {
                um[s[r]] = 1;
            }
            m = max(m, r-l+1);
            r++;
        }

        return m;


    }
};
