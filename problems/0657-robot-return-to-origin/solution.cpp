// 657. Robot Return to Origin [Easy]
// https://leetcode.com/problems/robot-return-to-origin/
// Language: C++ | Runtime: 0 ms | Memory: 10.5 MB

class Solution {
public:
    bool judgeCircle(string moves) {
        int x = 0, y = 0;
        for (char m : moves) {
            if (m == 'R') x++;
            else if (m == 'L') x--;
            else if (m == 'U') y++;
            else if (m == 'D') y--;
        }
        return x == 0 && y == 0;
    }
};
