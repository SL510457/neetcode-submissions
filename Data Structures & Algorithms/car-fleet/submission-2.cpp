class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();

        vector<pair<int,int>> cars(n);
        for(int i = 0; i < n; i++) {cars[i] = {position[i], speed[i]};}
        sort(cars.begin(), cars.end(), greater<>());
        
        stack<double> time;
    
        for(int i = 0; i < n; i++) {
            double curTime = ((double)target-(double)cars[i].first)/(double)cars[i].second;
            if(time.empty()) {
                time.push(curTime);
            }
            else {
                if(curTime > time.top())
                    time.push(curTime);
            }
        }
        return time.size();

    }
};