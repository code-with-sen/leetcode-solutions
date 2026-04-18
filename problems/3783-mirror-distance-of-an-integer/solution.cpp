// 3783. Mirror Distance of an Integer [Easy]
// https://leetcode.com/problems/mirror-distance-of-an-integer/
// Language: C++ | Runtime: 1 ms | Memory: 8.6 MB

class Solution {
public:
    int mirrorDistance(int n) {
        long long rev=0;
        for(int x=n; x; x/=10){
            rev=10*rev+x%10;
        }
        rev-=n;
        return rev>=0?rev:-rev;
    }
};
