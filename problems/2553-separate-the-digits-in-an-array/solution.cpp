// 2553. Separate the Digits in an Array [Easy]
// https://leetcode.com/problems/separate-the-digits-in-an-array/
// Language: C++ | Runtime: 0 ms | Memory: 15.4 MB

class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        
        vector<int> result;

        for (int num : nums) {

            string s = to_string(num);

            for (char ch : s) {

                result.push_back(ch - '0');
            }
        }

        return result;
    }
};
