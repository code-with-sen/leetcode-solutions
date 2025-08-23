// 18. 4Sum [Medium]
// https://leetcode.com/problems/4sum/
// Language: C++ | Runtime: 14 ms | Memory: 17.5 MB

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
    vector<vector<int>> ans;
    int n = nums.size();
    sort(nums.begin(),nums.end());
    for(int i = 0 ; i < n ; i++){
        if(i > 0 && nums[i] == nums[i -1]) continue;
        for(int j = i + 1;  j < n ;j++){
            if(j > i + 1 && nums[j] == nums[j - 1]) continue;

            long long target2 = (long long )target - nums[i] - nums[j];
            int l = j + 1;
            int r = n - 1;

            while(l < r){
                long sum = nums[l] + nums[r];
                if(sum < target2){
                    l++;
                }else if(sum > target2){
                    r--;
                }else{
                    ans.push_back({nums[i],nums[j],nums[l],nums[r]});

                    l++;
                    r--;

                    while(l < r && nums[l] == nums[l - 1]) l++;
                    while(l < r && nums[r] == nums[r + 1]) r--;
                }
            }
         }


    }

    return ans;

    }
};
