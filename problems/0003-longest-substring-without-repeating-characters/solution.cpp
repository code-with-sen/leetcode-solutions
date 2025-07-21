// 3. Longest Substring Without Repeating Characters [Medium]
// https://leetcode.com/problems/longest-substring-without-repeating-characters/
// Language: C++ | Runtime: 10 ms | Memory: 14.3 MB

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> seen;
        int left = 0 , right = 0 , maxlen = 0;

        while(right < s.length()){
            if(seen.find(s[right]) == seen.end()){
                seen.insert(s[right]);
                maxlen = max(maxlen , right - left + 1);
                right++;
            }else{
                seen.erase(s[left]);
                left++;
            }
        }
        return maxlen;
    }
};
