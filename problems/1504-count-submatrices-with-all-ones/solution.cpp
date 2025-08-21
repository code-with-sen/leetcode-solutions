// 1504. Count Submatrices With All Ones [Medium]
// https://leetcode.com/problems/count-submatrices-with-all-ones/
// Language: C++ | Runtime: 11 ms | Memory: 19.7 MB

class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> height(n, vector<int>(m, 0));
        int ans = 0;

        // Step 1: Precompute heights for consecutive 1's column-wise
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 1) {
                    height[i][j] = (i == 0) ? 1 : height[i-1][j] + 1;
                }
            }
        }

        // Step 2: For each row, use heights to count submatrices
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (height[i][j] > 0) {
                    int minHeight = height[i][j];
                    for (int k = j; k >= 0; k--) {
                        if (height[i][k] == 0) break;
                        minHeight = min(minHeight, height[i][k]);
                        ans += minHeight;
                    }
                }
            }
        }

        return ans;
    }
};
