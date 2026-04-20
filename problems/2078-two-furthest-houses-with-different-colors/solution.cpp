// 2078. Two Furthest Houses With Different Colors [Easy]
// https://leetcode.com/problems/two-furthest-houses-with-different-colors/
// Language: C++ | Runtime: 0 ms | Memory: 12.1 MB

class Solution {
public:
    int maxDistance(vector<int>& colors) {
        const int n=colors.size();
        int c0=colors[0], cN=colors[n-1];
        int lMax=0, rMax=0;
        for(int i=0; i<n; i++){
            int c=colors[i];
            if (c0!=c) lMax=max(lMax, i);
            if (cN!=c) rMax=max(rMax, n-1-i);
        }
        return max(lMax, rMax);
    }
};
