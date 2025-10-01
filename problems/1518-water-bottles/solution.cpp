// 1518. Water Bottles [Easy]
// https://leetcode.com/problems/water-bottles/
// Language: C++ | Runtime: 0 ms | Memory: 7.9 MB

class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int result = numBottles;
        int empty = numBottles;

        while (empty >= numExchange) {
            int newBottles = empty / numExchange;
            result += newBottles;
            empty = empty % numExchange + newBottles;
        }

        return result;
    }
};
