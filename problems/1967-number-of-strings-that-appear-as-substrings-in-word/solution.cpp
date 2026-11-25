// 1967. Number of Strings That Appear as Substrings in Word [Easy]
// https://leetcode.com/problems/number-of-strings-that-appear-as-substrings-in-word/
// Language: C++ | Runtime: 1 ms | Memory: 11.6 MB

class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int total = 0;
        for(string str : patterns)
        {
            if(word.find(str) != string::npos)
            {
                total++;
            }
        }
        return total;
    }
};
