// 2452. Words Within Two Edits of Dictionary [Medium]
// https://leetcode.com/problems/words-within-two-edits-of-dictionary/
// Language: C++ | Runtime: 0 ms | Memory: 12.6 MB

class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string> ans;

        for(string &q : queries){
            for(string &d : dictionary){
                int diff = 0;

                for(int i=0;i<q.size();i++){
                    if(q[i] != d[i]) diff++;
                    if(diff > 2) break;
                }

                if(diff <= 2){
                    ans.push_back(q);
                    break;
                }
            }
        }

        return ans;
    }
};
