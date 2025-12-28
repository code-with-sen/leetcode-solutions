// 1351. Count Negative Numbers in a Sorted Matrix [Easy]
// https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix/
// Language: C++ | Runtime: 0 ms | Memory: 14.2 MB

class Solution {
public:

    int countNegatives(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int totalCount = 0;

        
        for (int row = 0; row < rows; row++) {
           
            int left = 0;
            int right = cols - 1;
            int firstTrueIndex = -1;

            while (left <= right) {
                int mid = left + (right - left) / 2;
             
                if (grid[row][mid] < 0) {
                    firstTrueIndex = mid;
                    right = mid - 1;  // Search left for earlier negative
                } else {
                    left = mid + 1;  // search right for earlier negative
                }
            }

            // If we found a negative, count all elements from that index to end
            if (firstTrueIndex != -1) {
                totalCount += cols - firstTrueIndex;
            }
        }

        return totalCount;
    }
};
