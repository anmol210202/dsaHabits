class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int si = s.size();
        for(int i=1; i<=si/2; i++)
            if(s.substr(i)==s.substr(0,si-i) and s.size()%i==0) return true;
        return false;
    }
};
