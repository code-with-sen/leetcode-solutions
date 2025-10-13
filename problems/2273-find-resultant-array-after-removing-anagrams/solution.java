// 2273. Find Resultant Array After Removing Anagrams [Easy]
// https://leetcode.com/problems/find-resultant-array-after-removing-anagrams/
// Language: Java | Runtime: 2 ms | Memory: 45.2 MB

class Solution {
    public List<String> removeAnagrams(String[] words) {
        List<String> res = new ArrayList<>();
        String prev = "";
        
        for (String word : words) {
            char[] arr = word.toCharArray();
            Arrays.sort(arr);
            String sortedWord = new String(arr);
            
            if (!sortedWord.equals(prev)) {
                res.add(word);
                prev = sortedWord;
            }
        }
        
        return res;
    }
}
