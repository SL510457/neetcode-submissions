class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        map<int,int> mp;

        for(int i = 0; i < n; i++) {
            mp[hand[i]]++;
        }

        for (auto [val, count] : mp) {
            // cout << "val: " << val << " count: " << count << endl;
            if(count > 0) {
                mp[val] = 0;
                for(int i = 1; i < groupSize; i++) {
                    if(!mp.count(val+i) ||  mp[val+i] < count) {
                        // cout << "val: " << val+i << " count: " << mp.count(val+i) << endl;
                        return false;
                    }
                    else {
                        mp[val+i] -= count;
                    }
                }
            }
        }

        return true;
        // [1,1,2,2,3,3] groupSize=3

    }
};
