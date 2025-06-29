// 3597. Partition String  [Medium]
// https://leetcode.com/problems/partition-string/
// Language: C++ | Runtime: 234 ms | Memory: 111.7 MB

class Solution {
public:
    vector<string> partitionString(string s) {
        unordered_set<string> seen;
        vector<string> result;
        string current = "";

        for (char ch : s) {
            current += ch;

            // If current segment is not seen before
            if (seen.find(current) == seen.end()) {
                seen.insert(current);       // mark as seen
                result.push_back(current);  // add to result
                current = "";               // reset for next segment
            }
        }

        return result;
    }
};
