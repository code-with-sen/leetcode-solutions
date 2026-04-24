// 2833. Furthest Point From Origin [Easy]
// https://leetcode.com/problems/furthest-point-from-origin/
// Language: C++ | Runtime: 1 ms | Memory: 9.1 MB

class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int left = 0, right = 0, blanks = 0;

        for (char c : moves) {
            if (c == 'L') left++;
            else if (c == 'R') right++;
            else blanks++;
        }

        return abs(left - right) + blanks;
    }
};
