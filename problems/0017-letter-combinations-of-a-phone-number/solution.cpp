// 17. Letter Combinations of a Phone Number [Medium]
// https://leetcode.com/problems/letter-combinations-of-a-phone-number/
// Language: C++ | Runtime: 0 ms | Memory: 9.3 MB

class Solution {
public:
    void myletter(string digits, vector<string>& res, string nums[], int i, string s) {
        if(i == digits.length()) {
            res.push_back(s);
            return;
        }

         string val = nums[digits[i] - '0'];
        for(int j = 0; j < val.length(); j++) {
            myletter(digits, res, nums, i + 1, s + val[j]);
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if(digits.length() == 0)
            return res;

        string nums[10] = {
            "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
        };
        myletter(digits, res, nums, 0, "");
        return res;
    }
};
