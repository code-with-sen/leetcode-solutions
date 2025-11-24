// 1018. Binary Prefix Divisible By 5 [Easy]
// https://leetcode.com/problems/binary-prefix-divisible-by-5/
// Language: C++ | Runtime: 0 ms | Memory: 18.4 MB

class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        vector<bool> ans;
        int value = 0;

        for (int bit : nums) {
            value = (value * 2 + bit) % 5;
            ans.push_back(value == 0);
        }

        return ans;
    }
};
