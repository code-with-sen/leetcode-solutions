// 1541. Minimum Insertions to Balance a Parentheses String [Medium]
// https://leetcode.com/problems/minimum-insertions-to-balance-a-parentheses-string/
// Language: C++ | Runtime: 1 ms | Memory: 14.3 MB

class Solution {
public:
    static int minInsertions(string& s) {
        int p=0, k=0;
        for(char c: s){
            const bool isOpen=c=='(';
            p+=(isOpen<<1)-(!isOpen);
            const bool pOdd=p&1, pNeg=p<0;
            k+=(isOpen & pOdd)+(!isOpen & pNeg);
            p+=-(isOpen & pOdd)+((!isOpen & pNeg)<<1);
        }
        return p+k;
    }
};
