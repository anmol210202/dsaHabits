class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        map<char,int> m;
        for(auto &e:magazine) m[e]++;
        for(auto &e:ransomNote){
            if(m.find(e)!=m.end() and m[e]>0){
                m[e]--;
            }else return false;
        }
        return true;
    }
};
