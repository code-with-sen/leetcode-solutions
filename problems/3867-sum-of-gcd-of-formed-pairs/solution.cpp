// 3867. Sum of GCD of Formed Pairs [Medium]
// https://leetcode.com/problems/sum-of-gcd-of-formed-pairs/
// Language: C++ | Runtime: 66 ms | Memory: 148.8 MB

class Solution {
public:
    long long gcdSum(vector<int>& A) {
        int max = 0;

        for (int& n : A) {
            max = ::max(max, n);
            n = gcd(n, max);
        }

        ranges::sort(A);

        long long res = 0;
        for (int i = 0, j = A.size() - 1; i < j; i++, j--)
            res += gcd(A[i], A[j]);

        return res;
    }
};
