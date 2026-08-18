class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        int n = s.size();
        unordered_map<char,char> pairs = {{')','('}, {']','['},{'}','{'}};
        
        for(int i = 0; i < n; i++) {
            if(pairs.count(s[i])) {
                if(st.empty() || st.top() != pairs[s[i]])
                    return false;
                else
                    st.pop();
            }
            else
                st.push(s[i]);
        }

        if(st.empty())
            return true;
        return false;
    }
};
