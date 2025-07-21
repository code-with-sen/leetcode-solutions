// 73. Set Matrix Zeroes [Medium]
// https://leetcode.com/problems/set-matrix-zeroes/
// Language: C++ | Runtime: 0 ms | Memory: 18.5 MB

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        bool firstRow = false, firstCol = false;

        // Check if first row needs to be zero
        for (int j = 0; j < n; j++) {
            if (matrix[0][j] == 0) firstRow = true;
        }

        // Check if first column needs to be zero
        for (int i = 0; i < m; i++) {
            if (matrix[i][0] == 0) firstCol = true;
        }

        // Use 1st row and col to mark zeros
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        // Set cells to zero based on 1st row/col
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;
            }
        }

        // Zero out first row if needed
        if (firstRow) {
            for (int j = 0; j < n; j++)
                matrix[0][j] = 0;
        }

        // Zero out first column if needed
        if (firstCol) {
            for (int i = 0; i < m; i++)
                matrix[i][0] = 0;
        }
    }
};
