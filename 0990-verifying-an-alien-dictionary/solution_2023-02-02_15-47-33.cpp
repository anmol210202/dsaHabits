class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        vector<int> v(26,0);
        for(int i=0; i<order.size(); i++) v[order[i]-'a']=i;
        for(auto &e:words) for(auto &x:e) x=v[x-'a']+'a';
        return is_sorted(words.begin(),words.end());
    }
};
