class Solution {
public:
    string frequencySort(string s) {
        vector<pair<int,char>> v;
        unordered_map<char,int> m;
        for(auto &e:s) m[e]++;
        for(auto &e:m){
            pair<int,char> p;
            p.first=e.second;
            p.second=e.first;
            v.push_back(p);
        }
        sort(v.begin(),v.end(),greater<pair<int,char>>());
        s.clear();
        for(auto &e:v) for(e.first; e.first>0; e.first--) s+=e.second;
        return s;
    }
};
