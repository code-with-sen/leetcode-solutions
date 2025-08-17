// 3. Longest Substring Without Repeating Characters [Medium]
// https://leetcode.com/problems/longest-substring-without-repeating-characters/
// Language: C++ | Runtime: 20 ms | Memory: 14.4 MB

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> seen;
        int left = 0 , maxlen = 0 ;
        for(int right = 0 ; right < s.size();right++){
            while(seen.count(s[right])){
                seen.erase(s[left]);
                left++;
            }
            seen.insert(s[right]);
            maxlen = max(maxlen, right - left + 1);

        }
        return maxlen;
    }
};
