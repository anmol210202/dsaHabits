class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> v( m , vector<int> (n, 0));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(i==0 || j==0) v[j][i]=1;
                else v[j][i]=v[j-1][i]+v[j][i-1];
            }
        } 
        return v[m-1][n-1];
    }
};
