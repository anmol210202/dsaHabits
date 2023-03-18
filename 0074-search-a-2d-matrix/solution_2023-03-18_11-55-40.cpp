class Solution {
public:      
    bool searchMatrix(vector<vector<int>>& m, int t) {
        int r=0,c=m[0].size()-1;
        while(r<m.size() and c>=0){
            int cur=m[r][c];
            if(t==cur) return true;
            else if(t>cur) r++;
            else c--;
        }
        return false;
    }
};
