// 242. Valid Anagram [Easy]
// https://leetcode.com/problems/valid-anagram/
// Language: C++ | Runtime: 0 ms | Memory: 9.7 MB

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false;

        vector<int> drawer(26,0);// its an empty array basically (26 places)
        
        for(char ch : s) drawer[ch - 'a']++;  // ek se add karo 
        for(char ch : t) drawer[ch - 'a']--; // ek se sub kro 

        for(int count : drawer){
            if(count != 0 ) return false;  // anagram nhi ho
        }

        return true;  // zero hua mtlb ho tm anagram
    }
};
