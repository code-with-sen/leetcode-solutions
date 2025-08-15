// 342. Power of Four [Easy]
// https://leetcode.com/problems/power-of-four/
// Language: C++ | Runtime: 0 ms | Memory: 7.9 MB

class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n <= 0) return false;
        while(n % 4 == 0){
            n /= 4;
        }
        return n == 1;
    }
};
