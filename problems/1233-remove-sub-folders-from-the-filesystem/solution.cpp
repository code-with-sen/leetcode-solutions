// 1233. Remove Sub-Folders from the Filesystem [Medium]
// https://leetcode.com/problems/remove-sub-folders-from-the-filesystem/
// Language: C++ | Runtime: 58 ms | Memory: 47.5 MB

class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end());
        vector<string> result;
        
        for (string& f : folder) {
            if (result.empty() || f.find(result.back() + "/") != 0) {
                result.push_back(f);
            }
        }
        
        return result;
    }
};
