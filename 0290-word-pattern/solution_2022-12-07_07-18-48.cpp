class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char,string> m;
        vector<string> v;
        string s1;
        for(auto &e:s){
            if(e!=' '){
                s1+=e;
            }
            else{
                v.push_back(s1);
                s1.clear();
            }
        }
        v.push_back(s1);
        if(pattern.size()!=v.size()) return false;
        for(int i=0; i<pattern.size(); i++){
            if(m.count(pattern[i])!=1){
                m[pattern[i]]=v[i];
            }else {
                if(m[pattern[i]]!=v[i]) return false;
            }
        }
        for(auto &e:m){
            for(auto &r:m){
                if(e.first!=r.first and e.second==r.second) return false;
                break;
            }
        }
        return true;
    }
};
