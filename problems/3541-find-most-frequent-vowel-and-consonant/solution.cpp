// 3541. Find Most Frequent Vowel and Consonant [Easy]
// https://leetcode.com/problems/find-most-frequent-vowel-and-consonant/
// Language: C++ | Runtime: 0 ms | Memory: 9.5 MB

class Solution {
public:
    int maxFreqSum(string s) {
        array<int,26> cnt = {0};
        for (char c : s) {
            cnt[c - 'a']++;
        }
        auto isVowel = [&](char c) {
            return c=='a' || c=='e' || c=='i' || c=='o' || c=='u';
        };
        int maxVowel = 0, maxConsonant = 0;
        for (int i = 0; i < 26; i++) {
            char c = 'a' + i;
            if (isVowel(c)) {
                maxVowel = max(maxVowel, cnt[i]);
            } else {
                maxConsonant = max(maxConsonant, cnt[i]);
            }
        }
        return maxVowel + maxConsonant;
    }
};
