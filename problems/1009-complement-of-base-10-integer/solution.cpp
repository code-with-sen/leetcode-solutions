// 1009. Complement of Base 10 Integer [Easy]
// https://leetcode.com/problems/complement-of-base-10-integer/
// Language: C++ | Runtime: 0 ms | Memory: 7.7 MB

class Solution {
 public:
  int bitwiseComplement(int n) {
   int mask = 1;
   while(mask < n)
      mask = (mask << 1) + 1;
    return mask ^ n;
  }
};
