class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<int,int> m;
        // int st=0,l=0;
        // for(int i=0; i<s.size(); i++){
        //     if(m.find(s[i])!=m.end() and m[s[i]]>=st) st=1+m[s[i]];
        //     m[s[i]]=i;
        //     l=max(l,i-st+1);
        // }
        // return l;

        int startingPoint=0,len=0,n=s.size();
        for(int i=0; i<n; i++){
            if(m.find(s[i])!=m.end() and m[s[i]]>=startingPoint) startingPoint = m[s[i]] + 1;
            m[s[i]]=i;
            len = max(len , i- startingPoint +1);
        }

        return len; 
    }
};
