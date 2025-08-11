// 2438. Range Product Queries of Powers [Medium]
// https://leetcode.com/problems/range-product-queries-of-powers/
// Language: C++ | Runtime: 56 ms | Memory: 147.7 MB

class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        const int MOD = 1e9 + 7;

        // Extract the powers of two that sum up to n
        vector<long long> powers;
        int temp = n;
        while (temp > 0) {
            int low = temp & -temp; // lowest set bit
            powers.push_back(low);
            temp -= low;
        }

        // Precompute prefix products
        vector<long long> prefix(powers.size() + 1, 1);
        for (int i = 0; i < powers.size(); i++) {
            prefix[i + 1] = (prefix[i] * powers[i]) % MOD;
        }

        // Function for modular exponentiation (to get modular inverse)
        auto modPow = [&](long long base, long long exp) {
            long long result = 1;
            while (exp > 0) {
                if (exp & 1) result = (result * base) % MOD;
                base = (base * base) % MOD;
                exp >>= 1;
            }
            return result;
        };

        vector<int> ans;
        for (auto &q : queries) {
            int l = q[0], r = q[1];
            long long product = (prefix[r + 1] * modPow(prefix[l], MOD - 2)) % MOD;
            ans.push_back(product);
        }

        return ans;
    }
};
