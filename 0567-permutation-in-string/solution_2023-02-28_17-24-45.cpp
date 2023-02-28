class Solution {
public:
    bool check(vector<int> a,vector<int> b){
        for(auto i=0; i<26; i++) if(a[i]!=b[i]) return false;
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        if(s1.size()>s2.size()) return false;
        vector<int> v(26,0),tmp(26,0);
        for(auto &e:s1) v[e-'a']++;
        // first
        int k=s1.size();
        for(auto i=0; i<k; i++) tmp[s2[i]-'a']++;
        for(auto i=k; i<s2.size(); i++){
            if(check(tmp,v)) return true;
            tmp[s2[i]-'a']++,tmp[s2[i-k]-'a']--;
            // for(auto &e:tmp) cout<<e<<endl;
        }
        return check(tmp,v);
    }
};
