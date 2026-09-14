// 836. Rectangle Overlap [Easy]
// https://leetcode.com/problems/rectangle-overlap/
// Language: C++ | Runtime: 0 ms | Memory: 10 MB

class Solution {
public:
    bool isRectangleOverlap(auto& r1, auto& r2) {
        return r1[0] < r2[2] && r2[0] < r1[2] &&
               r1[1] < r2[3] && r2[1] < r1[3];
    }
};
