// 1493. Longest Subarray of 1's After Deleting One Element [Medium]
// https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element/
// Language: C++ | Runtime: 3 ms | Memory: 60.1 MB

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int left = 0 , zero = 0 , maxlen = 0;
        for(int right = 0 ; right < n ; right++){
            if(nums[right] == 0)
                zero++;

                while(zero > 1){
                    if(nums[left] == 0)
                        zero--;
                        left++;
                    

                    
                }
                maxlen = max(maxlen , right - left);
                
            }
        return maxlen;
    }
};
