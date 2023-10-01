class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& in) {
        sort(in.begin(), in.end());
        int n = in.size();
        vector<vector<int>> vv;
        if(n==0) return vv;
        int s=in[0][0],e=in[0][1];

        for(int i=1; i<n; i++){
            if(in[i][0]<=e){
                e=max(e,in[i][1]);
            } else {
                vv.push_back({s,e});
                s=in[i][0],e=max(e,in[i][1]);
            }
        }
        vv.push_back({s,e});

        return vv;   
    }
};
