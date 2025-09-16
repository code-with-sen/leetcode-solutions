// 2197. Replace Non-Coprime Numbers in Array [Hard]
// https://leetcode.com/problems/replace-non-coprime-numbers-in-array/
// Language: C++ | Runtime: 16 ms | Memory: 136.3 MB

class Solution {
public:
    int gcd(int a, int b) {
        while (b) {
            int t = b;
            b = a % b;
            a = t;
        }
        return a;
    }

    long long lcm(long long a, long long b) {
        return (a / gcd(a, b)) * b;
    }

    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<long long> st;  // use long long to avoid overflow during lcm
        for (int x : nums) {
            long long cur = x;
            // keep merging with stack top if gcd > 1
            while (!st.empty() && gcd(st.back(), cur) > 1) {
                cur = lcm(st.back(), cur);
                st.pop_back();
            }
            st.push_back(cur);
        }
        // convert back to int (guaranteed <= 1e8 as per problem)
        vector<int> ans;
        for (long long v : st) ans.push_back((int)v);
        return ans;
    }
};
