class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false; 
        int count[26] = {0}; 
        for(int i = 0; i < s.size(); i++) {
            count[s[i] - 'a']++; // Increment count for character in s
            count[t[i] - 'a']--; // Decrement count for character in t
        }
        for(int i = 0; i < 26; i++) {
            if(count[i] != 0) return false; // If any count is not zero, they are not anagrams
        }
        return true; // All counts are zero, so they are anagrams
    }
};