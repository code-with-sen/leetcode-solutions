// 36. Valid Sudoku [Medium]
// https://leetcode.com/problems/valid-sudoku/
// Language: C++ | Runtime: 0 ms | Memory: 21.7 MB

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int rows[9] = {0}, cols[9] = {0}, boxes[9] = {0};
        
        for (int r = 0; r < 9; ++r) {
            for (int c = 0; c < 9; ++c) {
                char ch = board[r][c];
                if (ch == '.') continue;
                int d = ch - '1';            // 0..8
                int bit = 1 << d;
                int b = (r/3)*3 + (c/3);     // box index 0..8
                
                if (rows[r] & bit) return false;
                if (cols[c] & bit) return false;
                if (boxes[b] & bit) return false;
                
                rows[r]  |= bit;
                cols[c]  |= bit;
                boxes[b] |= bit;
            }
        }
        return true;
    }
};
