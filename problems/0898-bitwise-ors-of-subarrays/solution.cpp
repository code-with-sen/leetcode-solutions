// 898. Bitwise ORs of Subarrays [Medium]
// https://leetcode.com/problems/bitwise-ors-of-subarrays/
// Language: C++ | Runtime: 948 ms | Memory: 230.2 MB

class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> result;
        unordered_set<int> curr, next;

        for (int num : arr) {
            next.clear();
            next.insert(num);
            for (int val : curr) {
                next.insert(val | num);
            }
            curr = next;
            result.insert(curr.begin(), curr.end());
        }

        return result.size();
    }
};
