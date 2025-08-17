// 2864. Maximum Odd Binary Number [Easy]
// https://leetcode.com/problems/maximum-odd-binary-number/
// Language: C++ | Runtime: 0 ms | Memory: 8.9 MB

class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int n = s.size();
        int N1 = 0 ;
        int N0 = 0 ;
        for(int i = 0 ; i < n ; i++){
            if( s[i] == '1') N1++;
         }
         N0 = n - N1;

        string ans = "";
         while(N1 > 1){
            ans += '1';
            N1--;
         }
         while(N0 > 0 ){
            ans += '0';
            N0--;
         }
         ans += '1';
         return ans;
    }
};
