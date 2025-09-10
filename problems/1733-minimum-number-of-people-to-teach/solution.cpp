// 1733. Minimum Number of People to Teach [Medium]
// https://leetcode.com/problems/minimum-number-of-people-to-teach/
// Language: C++ | Runtime: 230 ms | Memory: 148 MB

class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        int m = languages.size();  // Number of people
        
        // Store languages per person using unordered_set for O(1) lookup
        vector<unordered_set<int>> lang(m + 1);
        for (int i = 0; i < m; i++) {
            for (int l : languages[i]) {
                lang[i + 1].insert(l);
            }
        }
        
        // Step 1: Find friendships where they cannot communicate
        unordered_set<int> problematicPeople;
        for (auto &f : friendships) {
            int u = f[0], v = f[1];
            bool canCommunicate = false;
            
            // Check if they share any common language
            for (int l : lang[u]) {
                if (lang[v].count(l)) {
                    canCommunicate = true;
                    break;
                }
            }
            
            // If they can't communicate, mark them
            if (!canCommunicate) {
                problematicPeople.insert(u);
                problematicPeople.insert(v);
            }
        }
        
        // Step 2: Count how many problematic people know each language
        vector<int> freq(n + 1, 0);
        for (int person : problematicPeople) {
            for (int l : lang[person]) {
                freq[l]++;
            }
        }
        
        // Step 3: Find language with maximum coverage
        int maxKnown = 0;
        for (int i = 1; i <= n; i++) {
            maxKnown = max(maxKnown, freq[i]);
        }
        
        // Step 4: Result = total problematic - people who already know best language
        return problematicPeople.size() - maxKnown;
    }
};
