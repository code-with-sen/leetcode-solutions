// 169. Majority Element [Easy]
// https://leetcode.com/problems/majority-element/
// Language: C++ | Runtime: 0 ms | Memory: 28.3 MB

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0 ;
        int candidate = 0 ;

        for(int num : nums){
            if(count == 0){
                candidate = num;
            }
            count += (num == candidate) ? 1 : -1;
        }

        return candidate;
        
    }
};
