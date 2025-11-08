// 1611. Minimum One Bit Operations to Make Integers Zero [Hard]
// https://leetcode.com/problems/minimum-one-bit-operations-to-make-integers-zero/
// Language: C++ | Runtime: 0 ms | Memory: 8.1 MB

class Solution {
public:
    int minimumOneBitOperations(int n) {
         int ans = 0; 
        while(n != 0){
            ans = ans ^ n;
            n = n>>1;
        }
        return ans; 
    }
};
