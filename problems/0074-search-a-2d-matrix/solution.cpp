// 74. Search a 2D Matrix [Medium]
// https://leetcode.com/problems/search-a-2d-matrix/
// Language: C++ | Runtime: 0 ms | Memory: 13.4 MB

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        if(row == 0 ) return false;
        int col = matrix[0].size();
        int low = 0 , high = row * col -1 ;

        while(low <= high){
            int mid = low + (high - low ) / 2;
            int midelements = matrix[mid/col][mid%col];
            if(midelements == target)
                return true;
            else if(midelements < target )
                low = mid + 1;

            else
                high = mid - 1;
            
        }

        return false;
    }
};
