// 1980. Find Unique Binary String [Medium]
// https://leetcode.com/problems/find-unique-binary-string/
// Language: C++ | Runtime: 0 ms | Memory: 12.8 MB

class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int usedOnesCounts = 0;
       for (const auto& binaryStr : nums) {
            int onesCount = count(binaryStr.begin(), binaryStr.end(), '1');
            usedOnesCounts |= (1 << onesCount);
        }     
        for (int i = 0; ; ++i) {
            if ((usedOnesCounts >> i & 1) ^ 1) {            
                return string(i, '1') + string(nums.size() - i, '0');
            }
        }
    }
};
