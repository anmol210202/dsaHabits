class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int maxCount = 0; // Tracks the maximum count of a character in the sliding window
        int maxLength = 0; // Tracks the maximum length of the valid substring
        vector<int> charCount(26, 0); // Count of each character
        
        int start = 0; // Start of the sliding window

        for (int end = 0; end < n; ++end) {
            charCount[s[end] - 'A']++; // Increment the count of the current character
            maxCount = max(maxCount, charCount[s[end] - 'A']); // Update maxCount
            
            // Check if we need to shrink the window
            while (end - start + 1 - maxCount > k) {
                charCount[s[start] - 'A']--; // Decrement the count of the character at the start
                start++; // Move the start of the window
            }
            
            maxLength = max(maxLength, end - start + 1); // Update maxLength
        }
        
        return maxLength;
    }
};

