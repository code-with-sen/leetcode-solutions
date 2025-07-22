// 1856. Maximum Subarray Min-Product [Medium]
// https://leetcode.com/problems/maximum-subarray-min-product/
// Language: C++ | Runtime: 55 ms | Memory: 94.4 MB

class Solution {
public:
    int maxSumMinProduct(vector<int>& nums) {
        int n = nums.size();
        vector<long long> prefix(n+1 , 0 );
        for(int i = 0 ; i<n ; i++)
            prefix[i + 1 ] = prefix[i] + nums[i];
        vector<int> left(n), right(n);
        stack<int> s;

        for(int i = 0 ; i<n ; i++){
            while(!s.empty() && nums[s.top()] >= nums[i]) s.pop();
            left[i] = s.empty() ? 0 : s.top() + 1;
            s.push(i);
            }
            while(!s.empty()) s.pop();

            
        for(int i = n -1 ; i>= 0 ; i--){
            while(!s.empty() && nums[s.top()] >= nums[i]) s.pop();
            right[i] = s.empty() ? n-1 : s.top() - 1;
            s.push(i);
            }

            long long res = 0 ;
            for(int i = 0 ; i < n ; i++){
                long long total = prefix[right[i]+1] - prefix[left[i]];
                res = max(res, total *  nums[i]);
            
        }
        return res % 1000000007;
    }
};
