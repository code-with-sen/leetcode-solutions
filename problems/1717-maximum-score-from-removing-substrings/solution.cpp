// 1717. Maximum Score From Removing Substrings [Medium]
// https://leetcode.com/problems/maximum-score-from-removing-substrings/
// Language: C++ | Runtime: 67 ms | Memory: 39.8 MB

class Solution {
public:
    // Helper to remove substrings and return both score and remaining string
    pair<int, string> removePair(string s, char first, char second, int points) {
        stack<char> st;
        int score = 0;
        
        for (char c : s) {
            if (!st.empty() && st.top() == first && c == second) {
                st.pop();
                score += points;
            } else {
                st.push(c);
            }
        }
        
        // Construct the remaining string
        string remaining = "";
        while (!st.empty()) {
            remaining += st.top();
            st.pop();
        }
        reverse(remaining.begin(), remaining.end());
        
        return {score, remaining};
    }

    int maximumGain(string s, int x, int y) {
        int totalScore = 0;

        // Priority: remove higher scoring pair first
        if (x > y) {
            auto [score1, rem1] = removePair(s, 'a', 'b', x);  // remove "ab"
            auto [score2, rem2] = removePair(rem1, 'b', 'a', y);  // remove "ba"
            totalScore = score1 + score2;
        } else {
            auto [score1, rem1] = removePair(s, 'b', 'a', y);  // remove "ba"
            auto [score2, rem2] = removePair(rem1, 'a', 'b', x);  // remove "ab"
            totalScore = score1 + score2;
        }

        return totalScore;
    }
};
