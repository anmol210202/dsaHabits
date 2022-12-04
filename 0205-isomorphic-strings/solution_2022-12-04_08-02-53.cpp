class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,int> m,M;
        for(int i=0; i<s.size(); i++){
            if(m.find(s[i])!=m.end()){
                if(m[s[i]]!=t[i]) return false;
            }
            else{
                m[s[i]]=t[i];
            }
            if(M.find(t[i])!=M.end()){
                if(M[t[i]]!=s[i]) return false;
            }
            else{
                M[t[i]]=s[i];
            }
        }
        return true;
    }
};
