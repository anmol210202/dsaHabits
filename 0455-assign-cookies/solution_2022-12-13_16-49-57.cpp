class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int g_idx = 0;
        int s_idx = 0;
        while((s_idx<s.size()) and (g_idx<g.size())){
            if(s[s_idx]<g[g_idx]){
                ++s_idx;
                continue;
            }
            ++s_idx; ++g_idx;
        }
        return (g_idx);
    }
};
