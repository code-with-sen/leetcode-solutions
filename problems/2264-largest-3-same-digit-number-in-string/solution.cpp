// 2264. Largest 3-Same-Digit Number in String [Easy]
// https://leetcode.com/problems/largest-3-same-digit-number-in-string/
// Language: C++ | Runtime: 1 ms | Memory: 8.9 MB

class Solution {
public:
    string largestGoodInteger(string num) {
        string ans = "";
        for (int i = 0; i + 2 < num.size(); i++) {
            if (num[i] == num[i+1] && num[i] == num[i+2]) {
                string candidate = num.substr(i, 3);
                ans = max(ans, candidate);  // lexicographical max works for digits
            }
        }
        return ans;
    }
};
