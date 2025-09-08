// 1317. Convert Integer to the Sum of Two No-Zero Integers [Easy]
// https://leetcode.com/problems/convert-integer-to-the-sum-of-two-no-zero-integers/
// Language: C++ | Runtime: 0 ms | Memory: 8.3 MB

class Solution {
public:
    // Function to check if a number contains digit '0'
    bool hasZero(int num) {
        while (num > 0) {
            if (num % 10 == 0) return true;
            num /= 10;
        }
        return false;
    }

    vector<int> getNoZeroIntegers(int n) {
        for (int a = 1; a < n; ++a) {
            int b = n - a;
            if (!hasZero(a) && !hasZero(b)) {
                return {a, b};
            }
        }
        return {};
    }
};
