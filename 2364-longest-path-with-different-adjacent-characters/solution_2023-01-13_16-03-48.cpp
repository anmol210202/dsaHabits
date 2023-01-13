class Solution {
public:
    vector<vector<int>> v;
    int ans=1;
    int dfs(int u,int p,string &s){
        int t1=0,t2=0;
        for (auto e : v[u]) {
            if(e!=p){
                int tmp = dfs(e,u,s);
                ans = max(ans,tmp);
                if(s[u]!=s[e])
                if(tmp>t1){t2=t1; t1=tmp;}
                else t2=max(t2,tmp);
            }
        }
        ans=(max(ans,1+t1+t2));
        return 1+t1;
    }
    int longestPath(vector<int>& parent, string s) {
        v.resize(parent.size());
        for(int i=1; i<parent.size(); i++){
            v[parent[i]].push_back(i);
        }
        dfs(0,-1,s);
        return ans;
    }
};
