// 717. 1-bit and 2-bit Characters [Easy]
// https://leetcode.com/problems/1-bit-and-2-bit-characters/
// Language: C++ | Runtime: 0 ms | Memory: 13.1 MB

class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int i = 0;
        int n = bits.size();
        
        while (i < n - 1) {
            if (bits[i] == 1) {
                i += 2; // 2-bit character
            } else {
                i += 1; // 1-bit character
            }
        }
        
        return i == n - 1; // true if last is single-bit
    }
};
