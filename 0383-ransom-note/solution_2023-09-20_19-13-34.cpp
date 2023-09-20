class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<int,int> um;

        for(auto &e:magazine) um[e]++;

        for(auto &e:ransomNote) {
            if(um.find(e)!=um.end() and um[e]>0){
                um[e]--;
                
            } 
            else return false;
        }

        return true;
    }
};
