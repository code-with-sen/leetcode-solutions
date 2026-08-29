// 2948. Make Lexicographically Smallest Array by Swapping Elements [Medium]
// https://leetcode.com/problems/make-lexicographically-smallest-array-by-swapping-elements/
// Language: C++ | Runtime: 246 ms | Memory: 202.8 MB

class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& A, int limit) {
        vector<int> sorted = A;
        ranges::sort(sorted);
        vector<vector<int>> grps;
        unordered_map<int, int> map;
        int id = -1;

        for (int i = 0; i < sorted.size(); i++) {
            if (i == 0 || sorted[i] - sorted[i - 1] > limit) {
                grps.push_back({});
                id++;
            }
            grps[id].push_back(sorted[i]);
            map[sorted[i]] = id;
        }

        vector<int> idx(grps.size(), 0);

        for (int i = 0; i < A.size(); i++) {
            int cur = map[A[i]];
            A[i] = grps[cur][idx[cur]];
            idx[cur]++;
        }

        return A;
    }
};
