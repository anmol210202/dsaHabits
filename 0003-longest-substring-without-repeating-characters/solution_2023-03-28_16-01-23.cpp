class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<int,int> m;
        int st=0,l=0;
        for(int i=0; i<s.size(); i++){
            if(m.find(s[i])!=m.end() and m[s[i]]>=st) st=1+m[s[i]];
            m[s[i]]=i;
            l=max(l,i-st+1);
        }
        return l;
    }
};
