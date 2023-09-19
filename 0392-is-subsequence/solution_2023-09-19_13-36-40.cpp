class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i=0, j=0, ns=s.size() , nt = t.size();
        while(ns>i and nt>j){
            if(s[i]==t[j]) i++;
            j++;
        }
            // cout<<i<<" "<<j<<endl;
        return i==ns;
    }
};
