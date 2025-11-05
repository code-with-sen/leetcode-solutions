// 350. Intersection of Two Arrays II [Easy]
// https://leetcode.com/problems/intersection-of-two-arrays-ii/
// Language: C++ | Runtime: 4 ms | Memory: 14.9 MB

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int , int> mp;
        vector<int> result;

        for(int num : nums1){
            mp[num]++;
        }

        for(int num : nums2){
            if(mp[num] > 0){
                result.push_back(num);
                mp[num]--;
            }
        }

        return result;
    }
};
