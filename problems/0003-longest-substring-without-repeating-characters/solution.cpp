// 3. Longest Substring Without Repeating Characters [Medium]
// https://leetcode.com/problems/longest-substring-without-repeating-characters/
// Language: C++ | Runtime: 22 ms | Memory: 14.2 MB

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> seen;
        int left = 0 , maxLength = 0 ;
        for(int right = 0 ; right < s.size(); right++){
            while(seen.count(s[right])){
                seen.erase(s[left]);
                left++;
            }

            seen.insert(s[right]);
            maxLength = max(maxLength, right - left + 1);

        }

        return maxLength;
    }
};
