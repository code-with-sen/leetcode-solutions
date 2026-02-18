// 414. Third Maximum Number [Easy]
// https://leetcode.com/problems/third-maximum-number/
// Language: C++ | Runtime: 0 ms | Memory: 12.9 MB

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long first = LONG_MIN, second = LONG_MIN , third = LONG_MIN;
        for(int n : nums){
            if(n == first || n == second || n == third) continue;

           if(n > first){
            third = second;
            second = first;
            first = n;
           }else if(n > second){
            third = second;
            second = n;
           }else if(n > third){
            third = n;
           } 
        }

        return (third == LONG_MIN) ? first : third;
    }
};
