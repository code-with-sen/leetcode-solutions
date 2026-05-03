// 796. Rotate String [Easy]
// https://leetcode.com/problems/rotate-string/
// Language: C++ | Runtime: 0 ms | Memory: 8.1 MB

class Solution {
public:
    bool rotateString(string& s, string& goal) {
        return s.size()==goal.size() && (s+s).find(goal)!=-1;
    }
};
