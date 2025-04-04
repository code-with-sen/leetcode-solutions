// 48. Rotate Image [Medium]
// https://leetcode.com/problems/rotate-image/
// Language: C++ | Runtime: 0 ms | Memory: 10.3 MB

class Solution {
public:
    void rotate(vector<vector<int>>& mat) {
        int n = mat.size();
        for(int i = 0;i<n-1;i++){
            for(int j = i;j<n;j++){
                swap(mat[i][j],mat[j][i]);
            }
      }  

      for(int i = 0;i<n;i++){
        reverse(mat[i].begin(),mat[i].end());
      }
  }
};
