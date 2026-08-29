class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int left = 0, right = m*n-1;
        
        while(left <= right) {
            int mid = left + (right-left)/2;
            cout << "mid: " << mid << endl;
            cout << "m = " << mid/n << " n = " << mid%n << endl;
            cout << matrix[mid/n][mid%n] << endl;
            
            if(target < matrix[mid/n][mid%n])
                right = mid-1;
            else if (target > matrix[mid/n][mid%n])
                left = mid+1;
            else
                return true;

            
        }

        return false;

    }
};
