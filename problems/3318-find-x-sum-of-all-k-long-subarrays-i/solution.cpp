// 3318. Find X-Sum of All K-Long Subarrays I [Easy]
// https://leetcode.com/problems/find-x-sum-of-all-k-long-subarrays-i/
// Language: C++ | Runtime: 25 ms | Memory: 40.9 MB

class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        vector<int> ans;

        // Har subarray ke liye X-Sum calculate karenge
        for (int i = 0; i <= n - k; i++) {
            unordered_map<int, int> freq;

            // Count frequency of elements in current subarray
            for (int j = i; j < i + k; j++) {
                freq[nums[j]]++;
            }

            // frequency aur element dono store karenge
            vector<pair<int,int>> v;
            for (auto &p : freq) {
                v.push_back({p.second, p.first});  // {frequency, element}
            }

            // Sort by frequency desc, then value desc
            sort(v.begin(), v.end(), [&](auto &a, auto &b){
                if (a.first == b.first) return a.second > b.second;
                return a.first > b.first;
            });

            // Top x elements ka sum nikalo (frequency ke hisaab se)
            int sum = 0;
            unordered_set<int> keep;
            for (int j = 0; j < min(x, (int)v.size()); j++) {
                keep.insert(v[j].second);
            }

            // ab subarray traverse karke unhi elements ka sum lo
            for (int j = i; j < i + k; j++) {
                if (keep.count(nums[j])) sum += nums[j];
            }

            ans.push_back(sum);
        }

        return ans;
    }
};
