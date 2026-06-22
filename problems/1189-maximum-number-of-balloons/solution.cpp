// 1189. Maximum Number of Balloons [Easy]
// https://leetcode.com/problems/maximum-number-of-balloons/
// Language: C++ | Runtime: 0 ms | Memory: 8.7 MB

class Solution {
public:
    static int maxNumberOfBalloons(string& text) {
        int freq[26]={0};
        for(char c : text){
            freq[c-'a']++;
        }
        return min({freq[0], freq[1], freq['l'-'a']>>1, freq['o'-'a']>>1, freq['n'-'a']});
    }
};
