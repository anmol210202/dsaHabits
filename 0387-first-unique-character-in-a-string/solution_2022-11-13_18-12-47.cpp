class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,pair<int,int>> m;
        for(int i=0; i<s.size(); i++){
            m[s[i]].first++;
            m[s[i]].second = i;
        }
        int ans = 100001;
        for(auto &e:m) if(e.second.first==1) ans=min(ans,e.second.second);
        return (ans!=100001 ? ans:-1);
    }
};
