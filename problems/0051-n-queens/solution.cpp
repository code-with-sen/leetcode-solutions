// 51. N-Queens [Hard]
// https://leetcode.com/problems/n-queens/
// Language: C++ | Runtime: 2 ms | Memory: 10.5 MB

class Solution {
    private:
    vector<vector<string>> result ;
    vector<string> board;
    int n;

    bool isSafe(int row, int col, vector<string>& board){
        for(int i = 0 ; i<n ; i++){
            if(board[i][col] == 'Q')  return false;
        }
        for(int i = row  ,  j = col; i>=0 && j >=0 ; i--,j--){
            if(board[i][j] == 'Q')  return false;
        }
        for(int i = row , j = col ; i>=0 && j<n ; i--,j++){
            if(board[i][j] == 'Q')  return false;
       

        }
        return true;
    }
    void solve(int row){
        if(row==n){
            result.push_back(board);
            return;
        }





       for(int col = 0 ; col<n;col++){ 
        if(isSafe(row,col,board)){
        board[row][col] = 'Q';
        solve(row+1);
        board[row][col] = '.';
        }

        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        this->n = n ;
        string row (n , '.');
        for (int i = 0 ; i<n ; i++){
            board.push_back(row);
        }
            solve(0);
           return result ;
        
    }
};
