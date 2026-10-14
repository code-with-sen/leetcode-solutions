// 3723. Maximize Sum of Squares of Digits [Medium]
// https://leetcode.com/problems/maximize-sum-of-squares-of-digits/
// Language: C++ | Runtime: 80 ms | Memory: 75 MB

class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        // Step 1: the biggest possible digit sum is 9 * num
        if (sum > 9 * num) return "";

        string ans;

        // Step 2: fill every position from left to right
        while (num-- > 0) {
            int digit = min(9, sum);   // take as much as we can, at most 9
            ans += char('0' + digit);
            sum -= digit;
        }

        return sum == 0 ? ans : "";
    }
};
