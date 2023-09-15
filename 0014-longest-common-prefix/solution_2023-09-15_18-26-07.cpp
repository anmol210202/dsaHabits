class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) {
            return ""; // Return an empty string if the input vector is empty.
        }
        
        string prefix = strs[0]; // Initialize prefix with the first string
        int n = strs.size();
        
        for (int i = 1; i < n; i++) {
            while (strs[i].find(prefix) != 0) {
                prefix = prefix.substr(0, prefix.size() - 1); // Remove the last character from prefix
                if (prefix.empty()) {
                    return ""; // If the prefix becomes empty, there's no common prefix.
                }
            }
        }
        
        return prefix;
    }
};

