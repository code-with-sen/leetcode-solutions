// 213. House Robber II [Medium]
// https://leetcode.com/problems/house-robber-ii/
// Language: C++ | Runtime: 0 ms | Memory: 10.2 MB

class Solution {
public:
    int robliner(vector<int>& nums, int start , int end){
        int prev1 = 0 , prev2 = 0;
        for(int i = start ; i <= end ; i ++){
            int temp = max (prev1, prev2 +  nums[i]);
            prev2 = prev1;
            prev1 = temp;
        }
        return prev1;
    }
     int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 0 ) return 0 ;
        if(n == 1 ) return nums[0] ;
        if(n == 2 ) return max(nums[0], nums[1]) ;

        int option1 = robliner(nums,0,n-2);
        int option2 = robliner(nums,1,n-1);
        return max(option1, option2);
        
    }
};
