// 3498. Reverse Degree of a String [Easy]
// https://leetcode.com/problems/reverse-degree-of-a-string/
// Language: C++ | Runtime: 0 ms | Memory: 9.6 MB

class Solution {
public:
    int reverseDegree(string& s) {
        int sum=0, n=s.size();
        for(int i=0; i<n; i++) sum+=(i+1)*('z'-s[i]+1);
        return sum;
    }
};
