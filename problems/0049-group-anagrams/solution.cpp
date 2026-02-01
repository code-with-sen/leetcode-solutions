// 49. Group Anagrams [Medium]
// https://leetcode.com/problems/group-anagrams/
// Language: C++ | Runtime: 20 ms | Memory: 26.2 MB

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

    vector<vector<string>> ans;
    unordered_map<string,vector<string>> mp;

    for(auto str : strs){
        string s = str;
        sort(s.begin(),s.end());
        mp[s].push_back(str);
    }       

    for(auto x : mp){
        ans.push_back(x.second);
    }
 
     return ans;

    }
};
