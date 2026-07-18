// 1979. Find Greatest Common Divisor of Array [Easy]
// https://leetcode.com/problems/find-greatest-common-divisor-of-array/
// Language: C++ | Runtime: 0 ms | Memory: 16.3 MB

class Solution {
public:
    int findGCD(vector<int>& nums) {
        int mn = 1001 , mx=0;

        for(int i=0; i<nums.size(); i++){
            if(nums[i]<mn) mn = nums[i];
            if(nums[i] > mx) mx = nums[i];
        }

        return gcd(mn,mx);
    }
};
