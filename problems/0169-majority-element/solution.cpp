// 169. Majority Element [Easy]
// https://leetcode.com/problems/majority-element/
// Language: C++ | Runtime: 2379 ms | Memory: 28.2 MB

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();

        for(int val : nums){
            int  freq = 0;

            for(int el : nums){
                if(el == val){
                        freq ++;
                }
            }
            if(freq > n/2){
                return val;
            }
        }
        return -1;
    }
};
