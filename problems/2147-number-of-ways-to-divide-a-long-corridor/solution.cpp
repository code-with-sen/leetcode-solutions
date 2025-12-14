// 2147. Number of Ways to Divide a Long Corridor [Hard]
// https://leetcode.com/problems/number-of-ways-to-divide-a-long-corridor/
// Language: C++ | Runtime: 23 ms | Memory: 33.5 MB

class Solution {
 public:
  int numberOfWays(string corridor) {
    constexpr int kMod = 1'000'000'007;
    long ans = 1;
    int prevSeat = -1;
    int numSeats = 0;

    for (int i = 0; i < corridor.length(); ++i) {
      if (corridor[i] == 'S') {
        if (++numSeats > 2 && numSeats % 2 == 1)
          ans = ans * (i - prevSeat) % kMod;
        prevSeat = i;
      }
    }

    return numSeats > 1 && numSeats % 2 == 0 ? ans : 0;
  }
};
