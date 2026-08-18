class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        int n = s.size();
        
        // ()[]({[]})
        
        for(int i = 0; i < n; i++) {
            if(st.empty()) {
                st.push(s[i]);
            }
            else {
                char curT = st.top();
                if(s[i] == ')' && curT == '(')
                st.pop();
                else if(s[i] == ']' && curT == '[')
                st.pop();
                else if(s[i] == '}' && curT == '{')
                st.pop();
                else
                    st.push(s[i]);
            }
        }

        if(st.empty())
            return 1;
        return 0;
    }
};
