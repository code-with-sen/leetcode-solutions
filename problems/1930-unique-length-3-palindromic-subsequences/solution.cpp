// 1930. Unique Length-3 Palindromic Subsequences [Medium]
// https://leetcode.com/problems/unique-length-3-palindromic-subsequences/
// Language: C++ | Runtime: 69 ms | Memory: 14.2 MB

class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.size();
        vector<int> first(26, -1), last(26, -1);
        for (int i = 0; i < n; ++i) {
            int c = s[i] - 'a';
            if (first[c] == -1) first[c] = i;
            last[c] = i;
        }

        int ans = 0;
        for (int ch = 0; ch < 26; ++ch) {
            if (first[ch] == -1) continue;
            int L = first[ch], R = last[ch];
            if (L >= R - 1) continue; // no room for middle char
            vector<bool> seen(26, false);
            for (int i = L + 1; i <= R - 1; ++i) {
                seen[s[i] - 'a'] = true;
            }
            for (int k = 0; k < 26; ++k) if (seen[k]) ++ans;
        }
        return ans;
    }
};
