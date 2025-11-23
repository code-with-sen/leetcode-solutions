// 1262. Greatest Sum Divisible by Three [Medium]
// https://leetcode.com/problems/greatest-sum-divisible-by-three/
// Language: C++ | Runtime: 3 ms | Memory: 30.6 MB



class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int sum = 0;
        vector<int> rem1, rem2;

        for (int n : nums) {
            sum += n;
            if (n % 3 == 1) rem1.push_back(n);
            else if (n % 3 == 2) rem2.push_back(n);
        }

        sort(rem1.begin(), rem1.end());
        sort(rem2.begin(), rem2.end());

        if (sum % 3 == 0) return sum;

        if (sum % 3 == 1) {
            int remove1 = rem1.size() > 0 ? rem1[0] : INT_MAX;
            int remove2 = rem2.size() > 1 ? rem2[0] + rem2[1] : INT_MAX;
            return sum - min(remove1, remove2);
        }

        // sum % 3 == 2
        int remove1 = rem2.size() > 0 ? rem2[0] : INT_MAX;
        int remove2 = rem1.size() > 1 ? rem1[0] + rem1[1] : INT_MAX;
        return sum - min(remove1, remove2);
    }
};
