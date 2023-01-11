class Solution {
public:
    vector<vector<int>> g;
    int dfs(int u,int p,vector<bool>& hasApple){
     int res = 0, t = 0;
            for (auto v : g[u]) {
                if (p ^ v) {
                    t = dfs(v, u,hasApple);
                    if (t > 0 || hasApple[v]) {
                        res += t + 2;
                    }
                }
            }
            return res;
    }

    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        g.resize(n);
        for(auto &e:edges){
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);            
        }
        return dfs(0,-1,hasApple);
    }
};
