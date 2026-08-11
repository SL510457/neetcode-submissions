class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded_string = {};
        int n = strs.size();
        for(int i = 0; i < n; i++) {
            encoded_string += (to_string(strs[i].size())+"#"+strs[i]);
        }
        
        return encoded_string;
    }
    // ["Hello","World"]
    // 5#Hello5#World
    // 14


    vector<string> decode(string s) {
        int n = s.size();
        vector<string> decoded_strs;
        for(int i = 0; i < n; i++) {
            string str_size = {};
            while(s[i] != '#') {
                str_size += s[i];
                i++;
            }
            i++;
            int n = stoi(str_size);
            cout << n << endl;
            string cur = {};

            while(n>0) {
                cur += s[i];
                i++;
                n--;
            }
            i--;
            decoded_strs.push_back(cur);
        }
        return decoded_strs;
    }
};