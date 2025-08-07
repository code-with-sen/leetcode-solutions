// 3363. Find the Maximum Number of Fruits Collected [Hard]
// https://leetcode.com/problems/find-the-maximum-number-of-fruits-collected/
// Language: C++ | Runtime: 55 ms | Memory: 174 MB

class Solution {
public:
    int maxCollectedFruits(vector<vector<int>>& fruits) {
        int n = fruits.size();
        
        // Child 1: Can only move on main diagonal
        int diagonalSum = 0;
        for (int i = 0; i < n; i++) {
            diagonalSum += fruits[i][i];
        }
        
        // Child 2: DP for path from (0, n-1) - can only be in upper triangle
        vector<vector<int>> dp2(n, vector<int>(n, -1));
        dp2[0][n-1] = fruits[0][n-1];
        
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (j <= i) continue; // Only upper triangle (j > i)
                
                // Child 2 can come from three positions: (i-1,j-1), (i-1,j), (i-1,j+1)
                for (int prevJ = j-1; prevJ <= j+1; prevJ++) {
                    if (prevJ >= 0 && prevJ < n && prevJ > i-1 && dp2[i-1][prevJ] != -1) {
                        dp2[i][j] = max(dp2[i][j], dp2[i-1][prevJ] + fruits[i][j]);
                    }
                }
            }
        }
        
        // Child 3: DP for path from (n-1, 0) - can only be in lower triangle  
        vector<vector<int>> dp3(n, vector<int>(n, -1));
        dp3[n-1][0] = fruits[n-1][0];
        
        for (int j = 1; j < n; j++) {
            for (int i = 0; i < n; i++) {
                if (i <= j) continue; // Only lower triangle (i > j)
                
                // Child 3 can come from three positions: (i-1,j-1), (i,j-1), (i+1,j-1)
                for (int prevI = i-1; prevI <= i+1; prevI++) {
                    if (prevI >= 0 && prevI < n && prevI > j-1 && dp3[prevI][j-1] != -1) {
                        dp3[i][j] = max(dp3[i][j], dp3[prevI][j-1] + fruits[i][j]);
                    }
                }
            }
        }
        
        // Final answer: diagonal + max fruits child 2 can get at (n-2,n-1) + max fruits child 3 can get at (n-1,n-2)
        int child2Max = (dp2[n-2][n-1] != -1) ? dp2[n-2][n-1] : 0;
        int child3Max = (dp3[n-1][n-2] != -1) ? dp3[n-1][n-2] : 0;
        
        return diagonalSum + child2Max + child3Max;
    }
};

// Space-optimized version
class Solution2 {
public:
    int maxCollectedFruits(vector<vector<int>>& fruits) {
        int n = fruits.size();
        
        // Child 1: diagonal sum
        int result = 0;
        for (int i = 0; i < n; i++) {
            result += fruits[i][i];
        }
        
        // Child 2: Space-optimized DP
        vector<int> prev(n, -1), curr(n, -1);
        prev[n-1] = fruits[0][n-1];
        
        for (int i = 1; i < n; i++) {
            fill(curr.begin(), curr.end(), -1);
            for (int j = i + 1; j < n; j++) { // j > i (upper triangle)
                for (int prevJ = max(0, j-1); prevJ <= min(n-1, j+1); prevJ++) {
                    if (prevJ > i-1 && prev[prevJ] != -1) {
                        curr[j] = max(curr[j], prev[prevJ] + fruits[i][j]);
                    }
                }
            }
            prev = curr;
        }
        
        // Add child 2's result at (n-2, n-1)
        if (n >= 2 && prev[n-1] != -1) {
            result += prev[n-1];
        }
        
        // Child 3: Space-optimized DP  
        fill(prev.begin(), prev.end(), -1);
        prev[n-1] = fruits[n-1][0];
        
        for (int j = 1; j < n; j++) {
            fill(curr.begin(), curr.end(), -1);
            for (int i = j + 1; i < n; i++) { // i > j (lower triangle)
                for (int prevI = max(0, i-1); prevI <= min(n-1, i+1); prevI++) {
                    if (prevI > j-1 && prev[prevI] != -1) {
                        curr[i] = max(curr[i], prev[prevI] + fruits[i][j]);
                    }
                }
            }
            prev = curr;
        }
        
        // Add child 3's result at (n-1, n-2)
        if (n >= 2 && prev[n-1] != -1) {
            result += prev[n-1];
        }
        
        return result;
    }
};
