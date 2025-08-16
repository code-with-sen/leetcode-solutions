// 1323. Maximum 69 Number [Easy]
// https://leetcode.com/problems/maximum-69-number/
// Language: C++ | Runtime: 0 ms | Memory: 8 MB

class Solution {
public:
    int maximum69Number (int num) {
        string s = to_string(num);   // Convert number to string for easy digit handling
        for (char &c : s) {
            if (c == '6') {          // First time we see '6'
                c = '9';             // Change it to '9'
                break;               // Stop (only one change allowed)
            }
        }
        return stoi(s);              // Convert back to integer
    }
};
