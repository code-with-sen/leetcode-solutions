// 189. Rotate Array [Medium]
// https://leetcode.com/problems/rotate-array/
// Language: C++ | Runtime: 0 ms | Memory: 29.5 MB

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();

        k = k % n ;

        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k );
        reverse(nums.begin() + k , nums.end());
        
        

        
    }
};
