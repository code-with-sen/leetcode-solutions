// 3370. Smallest Number With All Set Bits [Easy]
// https://leetcode.com/problems/smallest-number-with-all-set-bits/
// Language: C++ | Runtime: 0 ms | Memory: 8.3 MB

class Solution {
public:
    int smallestNumber(int n) {
        int ans = 1;
        while (ans < n) {
            ans = (ans << 1) | 1; // make next all-1s number
        }
        return ans;
    }
};
