// 3003. Maximize the Number of Partitions After Operations [Hard]
// https://leetcode.com/problems/maximize-the-number-of-partitions-after-operations/
// Language: C++ | Runtime: 582 ms | Memory: 157.4 MB

class Solution {
public:
    int maxPartitionsAfterOperations(string s, int k) {
        int n = s.size();
        memo.clear();
        return dfs(s, 0, 0, 0, k) + 1;
    }

private:
    unordered_map<long long,int> memo;

    int dfs(const string &s, int i, int mask, int usedChange, int k) {
        int n = s.size();
        if (i == n) return 0;
        // Pack state into a key
        // i up to ~10^4, mask up to 2^26, usedChange in {0,1}
        long long key = ((long long)i << 27) | ((long long)usedChange << 26) | mask;
        auto it = memo.find(key);
        if (it != memo.end()) return it->second;

        int best = 0;

        // Option 1: use s[i] as is
        int bit = 1 << (s[i] - 'a');
        int newMask = mask | bit;
        if (__builtin_popcount(newMask) > k) {
            // must start new partition here
            best = 1 + dfs(s, i + 1, bit, usedChange, k);
        } else {
            best = dfs(s, i + 1, newMask, usedChange, k);
        }

        // Option 2: change s[i] to something else (if not used yet)
        if (usedChange == 0) {
            for (int c = 0; c < 26; ++c) {
                int newBit = 1 << c;
                int nm = mask | newBit;
                if (__builtin_popcount(nm) > k) {
                    best = max(best, 1 + dfs(s, i + 1, newBit, 1, k));
                } else {
                    best = max(best, dfs(s, i + 1, nm, 1, k));
                }
            }
        }

        memo[key] = best;
        return best;
    }
};
