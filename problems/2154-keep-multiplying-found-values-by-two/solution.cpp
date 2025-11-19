// 2154. Keep Multiplying Found Values by Two [Easy]
// https://leetcode.com/problems/keep-multiplying-found-values-by-two/
// Language: C++ | Runtime: 4 ms | Memory: 15.7 MB

class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        unordered_set<int> s(nums.begin(), nums.end());

        while (s.count(original)) {
            original *= 2;
        }

        return original;
    }
};
