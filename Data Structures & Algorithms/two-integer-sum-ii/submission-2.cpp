class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        vector<int> sol;
        int i = 0, j = n-1;
        
        while(i<j) {
            if(numbers[i]+numbers[j] > target) {
                j--;
            }
            else if(numbers[i]+numbers[j] < target) {
                i++;
            }
            else {
                sol.push_back(i+1);
                sol.push_back(j+1);
                break;
            }
        }

        return sol;
    }
};
