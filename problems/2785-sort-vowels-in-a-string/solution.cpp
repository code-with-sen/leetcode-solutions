// 2785. Sort Vowels in a String [Medium]
// https://leetcode.com/problems/sort-vowels-in-a-string/
// Language: C++ | Runtime: 28 ms | Memory: 17.8 MB

class Solution {
public:
    string sortVowels(string s) {
        string vowels = "aeiouAEIOU";
        unordered_set<char> vowelSet(vowels.begin(), vowels.end());
        
        // Step 1: Collect vowels
        vector<char> v;
        for (char c : s) {
            if (vowelSet.count(c)) v.push_back(c);
        }
        
        // Step 2: Sort vowels
        sort(v.begin(), v.end());
        
        // Step 3: Replace vowels in order
        int idx = 0;
        for (char &c : s) {
            if (vowelSet.count(c)) {
                c = v[idx++];
            }
        }
        
        return s;
    }
};
