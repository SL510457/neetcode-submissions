class Solution {
public:
    string s;
    vector<string> sol;
    void findCombine(unordered_map<char,vector<char>>& um, string& digits, int start) {
        if(start == (int)digits.size()) {
            sol.push_back(s);
            return;   
        }

        for(auto c:um[digits[start]]) {
            s += c;
            findCombine(um,digits,start+1);
            s.pop_back();
        }
            
    }
    vector<string> letterCombinations(string digits) {
        if(digits == "")
            return {};
        unordered_map<char,vector<char>> um;
        um['2'] = {'a','b','c'};
        um['3'] = {'d','e','f'};
        um['4'] = {'g','h','i'};
        um['5'] = {'j','k','l'};
        um['6'] = {'m','n','o'};
        um['7'] = {'p','q','r','s'};
        um['8'] = {'t','u','v'};
        um['9'] = {'w','x','y','z'};
        findCombine(um, digits, 0);
        return sol;
    }
};
