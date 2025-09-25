// 120. Triangle [Medium]
// https://leetcode.com/problems/triangle/
// Language: C++ | Runtime: 0 ms | Memory: 12.6 MB

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        // Start from the second last row and go upwards
        for (int row = n - 2; row >= 0; row--) {
            for (int col = 0; col <= row; col++) {
                // Update current cell with min path sum
                triangle[row][col] += min(triangle[row + 1][col], triangle[row + 1][col + 1]);
            }
        }
        return triangle[0][0]; // Top cell will have the answer
    }
};
