// 1344. Angle Between Hands of a Clock [Medium]
// https://leetcode.com/problems/angle-between-hands-of-a-clock/
// Language: C++ | Runtime: 0 ms | Memory: 8.1 MB

class Solution {
public:
    double angleClock(int hour, int minutes) {
        double x = hour + minutes / 60.0;
        double diff = fmod(11.0 * x, 12.0);
        return min(diff, 12.0 - diff) * 30.0;
    }
};
