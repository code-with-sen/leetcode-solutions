// 3461. Check If Digits Are Equal in String After Operations I [Easy]
// https://leetcode.com/problems/check-if-digits-are-equal-in-string-after-operations-i/
// Language: C++ | Runtime: 10 ms | Memory: 11.7 MB

class Solution {
public:
    bool hasSameDigits(const string& s) {
        int n = s.size();
        // Simple simulation will do for n up to ~100
        vector<int> arr(n);
        for (int i = 0; i < n; ++i) arr[i] = s[i] - '0';

        while (arr.size() > 2) {
            vector<int> temp(arr.size() - 1);
            for (int i = 0; i + 1 < arr.size(); ++i) {
                temp[i] = (arr[i] + arr[i + 1]) % 10;
            }
            arr = move(temp);
        }

        return (arr[0] == arr[1]);
    }
};
