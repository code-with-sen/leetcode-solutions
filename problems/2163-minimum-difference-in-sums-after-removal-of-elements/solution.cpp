// 2163. Minimum Difference in Sums After Removal of Elements [Hard]
// https://leetcode.com/problems/minimum-difference-in-sums-after-removal-of-elements/
// Language: C++ | Runtime: 137 ms | Memory: 154.7 MB

class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        int n = nums.size() / 3;
        int len = nums.size();
        
        vector<long long> left(len), right(len);
        priority_queue<int> maxHeap;
        priority_queue<int, vector<int>, greater<int>> minHeap;

        long long sum = 0;

        // Calculate prefix min sums of size n using maxHeap (for sumfirst)
        for (int i = 0; i < 2 * n; ++i) {
            sum += nums[i];
            maxHeap.push(nums[i]);

            if (maxHeap.size() > n) {
                sum -= maxHeap.top();
                maxHeap.pop();
            }

            if (maxHeap.size() == n) {
                left[i] = sum;
            }
        }

        sum = 0;

        // Calculate suffix max sums of size n using minHeap (for sumsecond)
        for (int i = len - 1; i >= n; --i) {
            sum += nums[i];
            minHeap.push(nums[i]);

            if (minHeap.size() > n) {
                sum -= minHeap.top();
                minHeap.pop();
            }

            if (minHeap.size() == n) {
                right[i] = sum;
            }
        }

        long long ans = LLONG_MAX;

        for (int i = n - 1; i < 2 * n; ++i) {
            ans = min(ans, left[i] - right[i + 1]);
        }

        return ans;
    }
};
