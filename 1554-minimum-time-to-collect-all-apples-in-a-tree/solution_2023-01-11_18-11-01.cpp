class Solution {
public:
    vector<vector<int>> v;
    int dfs(int u,int p,vector<bool>& hasApple){
     int ans = 0, temp = 0;
            for (auto e : v[u]) {
                if (p!=e) {
                    temp = dfs(e, u,hasApple);
                    if (temp > 0 || hasApple[e]) ans += temp + 2;
                }
            }
            return ans;
    }

    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        v.resize(n);
        for(auto &e:edges){
            v[e[0]].push_back(e[1]);
            v[e[1]].push_back(e[0]);            
        }
        return dfs(0,-1,hasApple);
    }
};
