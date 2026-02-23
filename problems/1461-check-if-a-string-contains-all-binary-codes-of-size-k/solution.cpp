// 1461. Check If a String Contains All Binary Codes of Size K [Medium]
// https://leetcode.com/problems/check-if-a-string-contains-all-binary-codes-of-size-k/
// Language: C++ | Runtime: 330 ms | Memory: 87.6 MB

class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int stringLength = s.size();
        int totalPossibleCodes = 1 << k;  // 2^k possible binary codes of length k
      
        // Early termination: if string doesn't have enough substrings, return false
        if (stringLength - k + 1 < totalPossibleCodes) {
            return false;
        }
      
        // Set to store unique binary substrings of length k
        unordered_set<string> uniqueSubstrings;
      
        // Iterate through all possible substrings of length k
        for (int i = 0; i + k <= stringLength; ++i) {
            // Extract substring of length k starting at index i and add to set
            uniqueSubstrings.insert(move(s.substr(i, k)));
        }
      
        // Check if we found all possible binary codes
        return uniqueSubstrings.size() == totalPossibleCodes;
    }
};
