class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int x = mat.size();
        int y = mat[0].size();
        if(r*c!=x*y) return mat;
        vector<vector<int>> ans;
        vector<int> temp;
        vector<int> odm;
        for(int i =0; i<x; i++){
            for(int j=0; j<y; j++){
                odm.push_back(mat[i][j]);
            }
        }
        for(int i=0; i<odm.size(); i++){
            if((i+1)%c==0){
                temp.push_back(odm[i]);
                ans.push_back(temp);
                temp.clear();
            } else{
                temp.push_back(odm[i]);
            }
        }
        return ans;
    }
};
