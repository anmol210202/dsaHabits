class Solution {
public:
    int lengthOfLastWord(string s) {
        int c = 0;
        int n = s.size();
        
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] != ' ') {
                c++;
            } else if (c > 0) {
                return c;
            }
        }
        
        return c;
    }
};

