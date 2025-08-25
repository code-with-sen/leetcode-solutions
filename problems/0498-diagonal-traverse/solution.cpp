// 498. Diagonal Traverse [Medium]
// https://leetcode.com/problems/diagonal-traverse/
// Language: C++ | Runtime: 0 ms | Memory: 22.2 MB

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<int> ans;
        ans.reserve(m * n);

        int row = 0, col = 0;
        bool up = true;

        while (ans.size() < m * n) {
            ans.push_back(mat[row][col]);

            if (up) {
                if (col == n - 1) {  // last column → move down
                    row++;
                    up = false;
                } else if (row == 0) {  // first row → move right
                    col++;
                    up = false;
                } else {  // normal up-right move
                    row--;
                    col++;
                }
            } else {
                if (row == m - 1) {  // last row → move right
                    col++;
                    up = true;
                } else if (col == 0) {  // first col → move down
                    row++;
                    up = true;
                } else {  // normal down-left move
                    row++;
                    col--;
                }
            }
        }
        return ans;
    }
};
