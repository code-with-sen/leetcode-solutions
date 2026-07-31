// 3016. Minimum Number of Pushes to Type Word II [Medium]
// https://leetcode.com/problems/minimum-number-of-pushes-to-type-word-ii/
// Language: Java | Runtime: 10 ms | Memory: 48.3 MB

class Solution {
    public int minimumPushes(String word) {
        int[] freq = new int[26];
        for (char c : word.toCharArray()) 
            freq[c - 'a']++;
        
        Arrays.sort(freq);
        int ans = 0;
        for (int i = 25; i >= 0 && freq[i] > 0; i--) 
            ans += freq[i] * ((25 - i) / 8 + 1);
        
        return ans;
    }
}
