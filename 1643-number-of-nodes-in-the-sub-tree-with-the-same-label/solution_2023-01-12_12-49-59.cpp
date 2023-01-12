class Solution {
public:
    vector<vector<int>> v;
    vector<int> a;
    vector<int> dfs(int u,int p,string &labels){
        vector<int> al(26,0);
        al[labels[u]-'a']=1;
        a[u]=1;
        for (auto e : v[u]) {
            if(e!=p){
                vector<int> tmp = dfs(e,u,labels);
                for(int k = 0; k != 26; k++) al[k] += tmp[k];
            }
            a[u]=al[labels[u]-'a'];
        }
        return al;
    }
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        v.resize(n);
        a.resize(labels.size());
        for(auto &e:edges){
            v[e[0]].push_back(e[1]);
            v[e[1]].push_back(e[0]);            
        }
        dfs(0,-1,labels);
        return a;
    }
};
