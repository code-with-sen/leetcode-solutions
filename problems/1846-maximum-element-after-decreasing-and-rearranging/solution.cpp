// 1846. Maximum Element After Decreasing and Rearranging [Medium]
// https://leetcode.com/problems/maximum-element-after-decreasing-and-rearranging/
// Language: C++ | Runtime: 0 ms | Memory: 57.3 MB

class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        int n = arr.size();
        vector<int> cnt(n + 1, 0);

        for (int x : arr) {
            cnt[min(x, n)]++;
        }

        int val = 0;

        for (int i = 1; i <= n; i++) {
            val = min(i, val + cnt[i]);
        }

        return val;
    }
};
