// 3005. Count Elements With Maximum Frequency [Easy]
// https://leetcode.com/problems/count-elements-with-maximum-frequency/
// Language: C++ | Runtime: 0 ms | Memory: 23.2 MB

class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int> freq;
        
        // Step 1: Count frequency of each element
        for (int num : nums) {
            freq[num]++;
        }
        
        // Step 2: Find maximum frequency
        int maxFreq = 0;
        for (auto &p : freq) {
            maxFreq = max(maxFreq, p.second);
        }
        
        // Step 3: Sum frequencies of elements that match maxFreq
        int result = 0;
        for (auto &p : freq) {
            if (p.second == maxFreq) {
                result += p.second;
            }
        }
        
        return result;
    }
};
