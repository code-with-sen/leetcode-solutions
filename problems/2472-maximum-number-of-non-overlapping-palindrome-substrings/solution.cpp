// 2472. Maximum Number of Non-overlapping Palindrome Substrings [Hard]
// https://leetcode.com/problems/maximum-number-of-non-overlapping-palindrome-substrings/
// Language: C++ | Runtime: 7 ms | Memory: 8.8 MB

class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.size(), ans = 0, end = -1;
        for(int i = 0; i < n; i++){
            // Even Length first, then Odd Length
            for(int l : {i - 1, i}){
                int r = i;
                // expand outward from the center
                while(l >= 0 && r < n && s[l] == s[r]){
                    if(r - l + 1 >= k && l > end){
                        ans++;
                        end = r;
                        break;
                    }
                    l--, r++;
                }
            }
        }
        return ans;
    }
};
