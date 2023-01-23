class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        unordered_map<int,vector<int>> m;
        // for(int i=1; i<=n; i++) m[i]=0;
        for(auto &e:trust) m[e[0]].push_back(e[1]);
        if(m.size()!=n-1) return -1;
        int x=0 , a=0;
        for(auto &e:m) x+=e.first;
        x-=n*(n+1)/2 , x*=-1;
        for(auto &e:m)for(auto &q:e.second)
        if(q==x) a++;
        return a==n-1 ? x:-1;
    }
};
