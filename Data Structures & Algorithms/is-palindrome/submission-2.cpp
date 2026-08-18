class Solution {
public:
    bool isPalindrome(string s) {
        string st = {};
        int n = s.size();
        for(int i = 0; i < n; i++) {
            if(isalnum(s[i])) {
                st += tolower(s[i]);
            }
        }
        
        
        n = st.size();
        for(int i = 0; i < n/2; i++) {
            if(st[i] != st[n-i-1])
                return false;
        }

        return true;;
    }
};
