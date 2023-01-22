class Solution {
public:
    bool c(string s, int st,int en){
        while(st<=en){
            if(s[st]!=s[en]) return false;
            st++,en--;
        }
        return true;
    }
    void bT(int i,string s, vector<vector<string>> &v,vector<string> &tmp){
        if(i==s.size()) {v.push_back(tmp); return ;}
        for(int j=i; j<s.size(); j++){
            if(c(s,i,j)){
                tmp.push_back(s.substr(i,j-i+1));
                bT(j+1,s,v,tmp);
                tmp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> v;
        vector<string> tmp;
        bT(0,s,v,tmp);
        return v;
    }
};
