// 239. Sliding Window Maximum [Hard]
// https://leetcode.com/problems/sliding-window-maximum/
// Language: C++ | Runtime: 13 ms | Memory: 139.2 MB

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

     deque<int> as;
     vector<int> result ;

     for(int i = 0 ; i < nums.size(); i++){
        if(!as.empty() && as.front() <= i-k){
            as.pop_front();
        }

        while(!as.empty() && nums[as.back()] < nums[i]){
            as.pop_back();
        }

        as.push_back(i);
     
        if(i >= k -1){
            result.push_back(nums[as.front()]);
          }
        }

        return result; 
    }
};
