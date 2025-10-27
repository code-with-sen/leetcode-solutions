// 2125. Number of Laser Beams in a Bank [Medium]
// https://leetcode.com/problems/number-of-laser-beams-in-a-bank/
// Language: C++ | Runtime: 3 ms | Memory: 27.2 MB

class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        long long prev = 0;
        long long ans = 0;
        for (const string &row : bank) {
            long long cnt = 0;
            for (char c : row) if (c == '1') ++cnt;
            if (cnt > 0) {
                if (prev > 0) ans += prev * cnt;
                prev = cnt;
            }
        }
        return (int)ans;
    }
};
