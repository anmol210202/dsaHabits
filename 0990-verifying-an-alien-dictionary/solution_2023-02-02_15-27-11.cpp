class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        vector<int> v(26,0);
        for(int i=0; i<order.size(); i++) v[order[i]-'a']=i;
        for(auto &e:words) for(auto &x:e) x=v[x-'a']+'a';
        vector<string> copy(words);
        sort(copy.begin(),copy.end());
        return copy==words ? true:false;
    }
};
