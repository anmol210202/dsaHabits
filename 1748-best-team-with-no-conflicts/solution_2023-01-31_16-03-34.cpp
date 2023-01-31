class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        vector<pair<int,int>> v;
        int ans=0 , tmp[ages.size()];
        for(int i=0; i<ages.size();i++) v.push_back({ages[i],scores[i]});
        sort(v.begin(),v.end());
        for(int i=0; i<ages.size(); i++){
            tmp[i]=v[i].second;
            for(int j=0; j<i; j++) if(v[j].second<=v[i].second) tmp[i]=max(tmp[i],tmp[j]+v[i].second);
            ans=max(ans,tmp[i]);
        }
        return ans;
    }
};
