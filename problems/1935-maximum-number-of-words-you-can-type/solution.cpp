// 1935. Maximum Number of Words You Can Type [Easy]
// https://leetcode.com/problems/maximum-number-of-words-you-can-type/
// Language: C++ | Runtime: 0 ms | Memory: 9.3 MB

class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        unordered_set<char> broken(brokenLetters.begin(), brokenLetters.end());
        
        int count = 0;
        string word;
        stringstream ss(text);
        
        while (ss >> word) {
            bool ok = true;
            for (char c : word) {
                if (broken.count(c)) {
                    ok = false;
                    break;
                }
            }
            if (ok) count++;
        }
        return count;
    }
};
