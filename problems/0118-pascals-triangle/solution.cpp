// 118. Pascal's Triangle [Easy]
// https://leetcode.com/problems/pascals-triangle/
// Language: C++ | Runtime: 0 ms | Memory: 9.6 MB

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> triangle;

        for (int i = 0; i < numRows; ++i) {
            vector<int> row(i + 1, 1); // first and last are 1
            for (int j = 1; j < i; ++j) {
                row[j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
            }
            triangle.push_back(row);
        }

        return triangle;
    }
};
