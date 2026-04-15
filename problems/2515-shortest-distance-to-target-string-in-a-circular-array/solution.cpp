// 2515. Shortest Distance to Target String in a Circular Array [Easy]
// https://leetcode.com/problems/shortest-distance-to-target-string-in-a-circular-array/
// Language: C++ | Runtime: 0 ms | Memory: 18.1 MB

class Solution {
public:
    static int closestTarget(vector<string>& words, string& target, int startIndex) {
        const int n=words.size();
        int d=0;
        for(; d<=n-1; d++){
            const int l=startIndex>=d?startIndex-d:n+startIndex-d;
            const int r=startIndex+d>=n?startIndex+d-n:startIndex+d;
            const string& x=words[l];
            const string& y=words[r];
            if (x==target || y==target) return d;
        }
        return -1;
        
    }
};
