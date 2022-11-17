class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()) return false;
        unordered_map<char,int> m;
        for(auto &e:t) m[e]++;
        for(auto &e:s){
            if(m.find(e)!=m.end() and m[e]>0) m[e]--;
            else return false;
        }
        return true;
    }
};
