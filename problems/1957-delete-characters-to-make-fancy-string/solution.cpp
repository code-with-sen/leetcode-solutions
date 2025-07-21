// 1957. Delete Characters to Make Fancy String [Easy]
// https://leetcode.com/problems/delete-characters-to-make-fancy-string/
// Language: C++ | Runtime: 45 ms | Memory: 44.6 MB

class Solution {
public:
    string makeFancyString(string s) {
        string result = "";
        for (int i = 0; i < s.length(); ++i) {
            int n = result.length();
            // Check if the last two characters in result are the same as s[i]
            if (n >= 2 && result[n - 1] == s[i] && result[n - 2] == s[i]) {
                continue; // skip current character
            }
            result += s[i]; // add to result
        }
        return result;
    }
};
