// 3360. Stone Removal Game [Easy]
// https://leetcode.com/problems/stone-removal-game/
// Language: C++ | Runtime: 0 ms | Memory: 7.5 MB

class Solution {
public:
    bool canAliceWin(int n) {
        int remove = 10;
        bool aliceTurn = true;

        while (n >= remove) {
            n -= remove;
            remove--;
            aliceTurn = !aliceTurn;
        }

        return !aliceTurn;
    }
};
