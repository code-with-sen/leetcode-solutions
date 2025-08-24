// 3658. GCD of Odd and Even Sums [Easy]
// https://leetcode.com/problems/gcd-of-odd-and-even-sums/
// Language: C++ | Runtime: 0 ms | Memory: 8.5 MB

class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        long long sumOdd = 1LL * n * n;
        long long sumEven = 1LL * n * (n + 1); 

        return std::gcd(sumOdd, sumEven); 
    }
};
