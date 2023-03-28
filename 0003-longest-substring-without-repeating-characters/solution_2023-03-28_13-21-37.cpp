class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> m;
        int start = 0, maxLen = 0, n = s.size();
        for (int end = 0; end < n; end++) {
            char c = s[end];
            if (m.find(c) != m.end() && m[c] >= start) { // repeat character found
                start = m[c] + 1; // update start index to next index after last occurrence
            }
            m[c] = end; // update last index of character
            maxLen = max(maxLen, end - start + 1); // update maximum length
        }
        return maxLen;
    }
};

