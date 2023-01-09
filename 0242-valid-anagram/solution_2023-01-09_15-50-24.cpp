class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        
        int len = s.size();
        int leng = t.size();
        if(len == leng) {
            for(int i = 0; i < len; i++) {
                if(s[i] != t[i])
                        return false;
            }
            return true;
        }
        else 
            return false;
        return true;
    }
};
