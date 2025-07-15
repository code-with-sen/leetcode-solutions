// 70. Climbing Stairs [Easy]
// https://leetcode.com/problems/climbing-stairs/
// Language: C++ | Runtime: 0 ms | Memory: 7.7 MB

class Solution {
public:
    int climbStairs(int n) {
        if(n == 1) return 1;
        if(n == 2) return 2;

        int first = 1, second = 2;

        for(int i = 3 ; i<= n ; i++){
            int current = first + second;
            first = second;
            second = current ;
        }

        return second;
    }
};
