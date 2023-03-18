class Solution {
public:      
    bool searchMatrix(vector<vector<int>>& m, int t) {
        int r=m.size(),c=m[0].size(),s=0,e=r*c-1,mid=s+(e-s)/2;
        while(s<=e){
            int i=mid/c,j=mid%c; // trick
            if(m[i][j]==t) return true;
            else if(m[i][j]>t) e=--mid;
            else s=++mid;
            mid = s+(e-s)/2;
        }
        return false;
    }
};
