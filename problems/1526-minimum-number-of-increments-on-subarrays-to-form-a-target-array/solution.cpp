// 1526. Minimum Number of Increments on Subarrays to Form a Target Array [Hard]
// https://leetcode.com/problems/minimum-number-of-increments-on-subarrays-to-form-a-target-array/
// Language: C++ | Runtime: 0 ms | Memory: 76.9 MB

class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int res = target[0];
        for (int i = 1; i < target.size(); i++) {
            if (target[i] > target[i - 1])
                res += target[i] - target[i - 1];
        }
        return res;
    }
};
