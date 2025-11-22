// 3190. Find Minimum Operations to Make All Elements Divisible by Three [Easy]
// https://leetcode.com/problems/find-minimum-operations-to-make-all-elements-divisible-by-three/
// Language: C++ | Runtime: 0 ms | Memory: 23.3 MB

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int ops = 0;
        for(int x : nums){
            if(x % 3 != 0)
                ops++;
        }
        return ops;
    }
};
