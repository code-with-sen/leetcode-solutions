// 2169. Count Operations to Obtain Zero [Easy]
// https://leetcode.com/problems/count-operations-to-obtain-zero/
// Language: C++ | Runtime: 0 ms | Memory: 7.8 MB

class Solution {
public:
    long long countOperations(int num1, int num2) {
        long long ops = 0;
        while (num1 && num2) {
            if (num1 >= num2) {
                ops += num1 / num2;
                num1 %= num2;
            } else {
                ops += num2 / num1;
                num2 %= num1;
            }
        }
        return ops;
    }
};
