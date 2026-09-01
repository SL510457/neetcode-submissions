class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int leftk = 1, rightk = 1;

        for(int i = 0; i < n; i++) {
            rightk = max(rightk, piles[i]);
        }
        
        while(leftk <= rightk) {
            int mid = leftk + (rightk-leftk)/2;
            int curh = 0;
            for(int i = 0; i < n; i++) {
                curh += (piles[i]/mid);
                if(piles[i]%mid != 0)
                    curh++; 
            }
            
            if(curh > h)
                leftk = mid+1;
            else if(curh <= h) {
                rightk = mid-1;
            }
        }

        return leftk;
        


    }
};
