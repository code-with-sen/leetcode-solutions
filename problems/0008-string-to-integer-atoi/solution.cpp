// 8. String to Integer (atoi) [Medium]
// https://leetcode.com/problems/string-to-integer-atoi/
// Language: C++ | Runtime: 0 ms | Memory: 9 MB

class Solution {
public:
    int myAtoi(string s) {
        int i = 0, n = s.size();
        long result = 0;  // use long temporarily for safety
        int sign = 1;

        // 1. Skip leading spaces
        while (i < n && s[i] == ' ') i++;

        // 2. Check sign
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }

        // 3. Process digits
        while (i < n && isdigit(s[i])) {
            int digit = s[i] - '0';

            // 4. Check overflow before updating
            if (result > (INT_MAX - digit) / 10) {
                return (sign == 1) ? INT_MAX : INT_MIN;
            }

            result = result * 10 + digit;
            i++;
        }

        return result * sign;
    }
};
