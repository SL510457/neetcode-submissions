class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_set<string> trip;
        int n = paths.size();
        for(int i = 0; i < n; i++) {
            trip.insert(paths[i][0]);
        }

        for(int i = 0; i < n; i++) {
            if(trip.find(paths[i][1]) == trip.end()) {
                return paths[i][1];
            }
        }

        return "";
    }
};
