// 1967. Number of Strings That Appear as Substrings in Word [Easy]
// https://leetcode.com/problems/number-of-strings-that-appear-as-substrings-in-word/
// Language: C++ | Runtime: 0 ms | Memory: 11.6 MB

class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int ans = 0;

        for (string &s : patterns) {
            if (word.find(s) != string::npos)
                ans++;
        }

        return ans;
    }
};
