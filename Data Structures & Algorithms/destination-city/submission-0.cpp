class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_set<string> trip;
        unordered_set<string> city;
        int n = paths.size();
        for(int i = 0; i < n; i++) {
            trip.insert(paths[i][0]);
            city.insert(paths[i][0]);
            city.insert(paths[i][1]);
        }

        for(auto c : city) {
            if(trip.find(c) == trip.end()) {
                return c;
            }
        }

        return "";
    }
};
