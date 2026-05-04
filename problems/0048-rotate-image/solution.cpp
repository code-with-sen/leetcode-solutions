// 48. Rotate Image [Medium]
// https://leetcode.com/problems/rotate-image/
// Language: C++ | Runtime: 0 ms | Memory: 10.3 MB

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int i = 0 ; i < n - 1 ; i++){
            for(int j = i + 1; j < n ;j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }

        for(int i = 0 ; i < n ; i++){
            reverse(matrix[i].begin(),matrix[i].end());
        }
    }
};
