// 3. Longest Substring Without Repeating Characters [Medium]
// https://leetcode.com/problems/longest-substring-without-repeating-characters/
// Language: C++ | Runtime: 23 ms | Memory: 14.2 MB

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> seen;
        int left = 0, right = 0, maxLen = 0;

        while (right < s.length()) {
            if (seen.find(s[right]) == seen.end()) {
                // ✅ If character not seen yet
                seen.insert(s[right]);
                maxLen = max(maxLen, right - left + 1);
                right++;
            } else {
                // ❌ Character already seen, shrink window
                seen.erase(s[left]);
                left++;
            }
        }

        return maxLen;
    }
};
