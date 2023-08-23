class Solution {
public:
    string reorganizeString(string s) {
        int charCount[26] = {0}; // Array to store character frequencies
        int maxFreq = 0;
        char maxChar = 'a';
        
        for (char c : s) {
            charCount[c - 'a']++;
            if (charCount[c - 'a'] > maxFreq) {
                maxFreq = charCount[c - 'a'];
                maxChar = c;
            }
        }
        
        int n = s.size();
        if (maxFreq > (n + 1) / 2) {
            return ""; // Not possible to rearrange
        }
        
        string result(n, ' ');
        int idx = 0;
        
        // Fill even indices first
        while (charCount[maxChar - 'a'] > 0) {
            result[idx] = maxChar;
            idx += 2;
            charCount[maxChar - 'a']--;
        }
        
        // Fill remaining indices
        for (int i = 0; i < 26; ++i) {
            while (charCount[i] > 0) {
                if (idx >= n) {
                    idx = 1; // Start filling odd indices
                }
                result[idx] = 'a' + i;
                idx += 2;
                charCount[i]--;
            }
        }
        
        return result;
    }
};

