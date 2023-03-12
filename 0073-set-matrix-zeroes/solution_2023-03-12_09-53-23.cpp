class Solution {
public:
    void setZeroes(vector<vector<int>>& ma) {
        int m=ma.size(),n=ma[0].size();
        vector<pair<int,int>> v;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(ma[i][j]==0) v.push_back(make_pair(i,j));
            }
        }
        for(auto &e:v){
            for(int i=0; i<m; i++) ma[i][e.second]=0;
            for(int j=0; j<n; j++) ma[e.first][j]=0;
        }
    }
};
