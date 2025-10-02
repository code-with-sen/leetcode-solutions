// 3100. Water Bottles II [Medium]
// https://leetcode.com/problems/water-bottles-ii/
// Language: C++ | Runtime: 5 ms | Memory: 8.4 MB

class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int ans = numBottles;
        int empty = numBottles;

        while (empty >= numExchange) {
            // Use numExchange empty bottles to get 1 full bottle
            empty -= numExchange;
            // After getting that full, numExchange increases
            ++numExchange;
            // Drink that new bottle => increase ans
            ++ans;
            // Drinking yields 1 empty bottle
            ++empty;
        }

        return ans;
    }
};
