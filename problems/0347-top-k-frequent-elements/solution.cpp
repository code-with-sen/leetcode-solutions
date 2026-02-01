// 347. Top K Frequent Elements [Medium]
// https://leetcode.com/problems/top-k-frequent-elements/
// Language: C++ | Runtime: 0 ms | Memory: 18 MB

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;  // key and values ke liye 

        for(int num : nums){
            freq[num]++;  // count ke liye  
        }

        priority_queue<pair<int, int>, vector<pair<int,int>>, greater<>> pq;

         for ( auto &it : freq){  // min heap ka use 
            pq.push({it.second,it.first}); // key aur value ko store karo 

            if(pq.size() > k) { // k se bada hai toh delete kr dena 
                pq.pop();
            }
        }

        vector<int> ans;  // ans mei add karunga 

        while(!pq.empty()){  // jb tk khtm nh ho chalte rhna 
            ans.push_back(pq.top().second);  // top ke value ko add karo 
            pq.pop(); // aur ek ek krke delete karna 
        }

        return ans;  // ans ko return kar do.
    }
};
