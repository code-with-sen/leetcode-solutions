// 3227. Vowels Game in a String [Medium]
// https://leetcode.com/problems/vowels-game-in-a-string/
// Language: C++ | Runtime: 13 ms | Memory: 19.7 MB

class Solution {
public:
    bool doesAliceWin(string s) {
        string vowels = "aeiou";
        unordered_set<char> vowelSet(vowels.begin(), vowels.end());
        
        for (char c : s) {
            if (vowelSet.count(c)) {
                return true; // At least one vowel → Alice wins
            }
        }
        return false; // No vowels → Alice cannot move
    }
};
