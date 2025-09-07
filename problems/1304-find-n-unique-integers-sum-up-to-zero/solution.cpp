// 1304. Find N Unique Integers Sum up to Zero [Easy]
// https://leetcode.com/problems/find-n-unique-integers-sum-up-to-zero/
// Language: C++ | Runtime: 0 ms | Memory: 9.6 MB

class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> ans;
        ans.reserve(n);
        for (int i = 1; i <= n/2; ++i) {
            ans.push_back(i);
            ans.push_back(-i);
        }
        if (n % 2 == 1) ans.push_back(0);
        return ans;
    }
};
