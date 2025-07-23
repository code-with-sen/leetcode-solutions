// 410. Split Array Largest Sum [Hard]
// https://leetcode.com/problems/split-array-largest-sum/
// Language: C++ | Runtime: 0 ms | Memory: 10.4 MB

class Solution {
public:
    bool canpossible(vector<int>& nums, int k , int maxsum){
        int count = 1;
        long long currsum = 0 ;
        for(int num : nums){
            if(currsum + num > maxsum){
                count++;
                currsum = 0 ;
            }
            currsum += num;
        }
        return count <= k ;
    }



    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(),nums.end());
        int high = accumulate(nums.begin(),nums.end(),0);
        int ans = high;

        while(low <= high){
            int mid = low + ( high - low)/2;
            if(canpossible(nums,k,mid)){
                ans = mid ;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return ans;
    }
};
