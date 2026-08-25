class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int n = tokens.size();
        stack<int> s;

        for(int i = 0; i < n; i++) {
            if(tokens[i].size() > 1 || isdigit(tokens[i][0])) {
                int num = stoi(tokens[i]);
                s.push(num);
            }
            else {
                int b = s.top();
                s.pop();
                int a = s.top();
                s.pop();
                if(tokens[i] == "+") 
                    s.push(a+b);
                else if(tokens[i] == "-")
                    s.push(a-b);
                else if(tokens[i] == "*")
                    s.push(a*b);
                else
                    s.push(a/b); 
            }
        }

        int sol = s.top();
        return sol;
    }
};
