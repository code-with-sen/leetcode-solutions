// 966. Vowel Spellchecker [Medium]
// https://leetcode.com/problems/vowel-spellchecker/
// Language: C++ | Runtime: 44 ms | Memory: 41.5 MB

class Solution {
public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        unordered_set<string> exact(wordlist.begin(), wordlist.end());
        unordered_map<string, string> caseMap;
        unordered_map<string, string> vowelMap;
        
        auto devowel = [](string w) {
            for (char &c : w) {
                if (c=='a'||c=='e'||c=='i'||c=='o'||c=='u') c = '*';
            }
            return w;
        };
        
        for (string &w : wordlist) {
            string lower = w;
            for (char &c : lower) c = tolower(c);
            
            if (!caseMap.count(lower)) caseMap[lower] = w;
            string dv = devowel(lower);
            if (!vowelMap.count(dv)) vowelMap[dv] = w;
        }
        
        vector<string> ans;
        for (string q : queries) {
            if (exact.count(q)) {
                ans.push_back(q);
                continue;
            }
            string lower = q;
            for (char &c : lower) c = tolower(c);
            
            if (caseMap.count(lower)) {
                ans.push_back(caseMap[lower]);
                continue;
            }
            string dv = devowel(lower);
            if (vowelMap.count(dv)) {
                ans.push_back(vowelMap[dv]);
                continue;
            }
            ans.push_back("");
        }
        return ans;
    }
};
