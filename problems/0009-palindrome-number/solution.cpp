// 9. Palindrome Number [Easy]
// https://leetcode.com/problems/palindrome-number/
// Language: C++ | Runtime: 0 ms | Memory: 8.6 MB

class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0 || (x % 10 == 0 && x != 0 )) return false;

        int reversehalf = 0 ;
        while(x > reversehalf){
            reversehalf = reversehalf*10 + x % 10 ;
            x /= 10;
        }
        return ( x == reversehalf) || (x == reversehalf/10);
    }
};
