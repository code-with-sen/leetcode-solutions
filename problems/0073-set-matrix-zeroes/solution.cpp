// 73. Set Matrix Zeroes [Medium]
// https://leetcode.com/problems/set-matrix-zeroes/
// Language: C++ | Runtime: 0 ms | Memory: 18.6 MB

class Solution {
public:
    void setZeroes(vector<vector<int>>& mt) {
        int m = mt.size();
        int n = mt[0].size();

        bool FR = false;
        bool FC = false;

        for(int j = 0;j<n;j++){
            if(mt[0][j] == 0){
                FR = true;
                break;
            }
        }
        for(int i = 0;i<m;i++){
            if(mt[i][0] == 0){
                FC = true;
                break;
            }
        }

        for(int i =1;i<m;i++){
            for(int j=1;j<n;j++){
                if(mt[i][j] == 0){
                    mt[i][0]=0;
                    mt[0][j]=0;
                }
            }
        }

        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(mt[i][0] == 0 || mt[0][j] == 0){
                    mt[i][j] = 0;
                }
            }
        }

        if (FR){
            for(int j =0;j<n;j++){
                mt[0][j] =0;
            }
        }

        if (FC){
            for(int i =0;i<m;i++){
                mt[i][0] =0;
            }
        }

    }
};
