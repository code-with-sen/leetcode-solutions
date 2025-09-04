// 3516. Find Closest Person [Easy]
// https://leetcode.com/problems/find-closest-person/
// Language: C++ | Runtime: 0 ms | Memory: 8.7 MB

class Solution {
public:
    int findClosest(int x, int y, int z) {
        int dist1 = abs(x - z);
        int dist2 = abs(y - z);
        if (dist1 == dist2) return 0;
        return (dist1 < dist2) ? 1 : 2;
    }
};
