class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
       int r0 = mat.size(), c0 = mat[0].size();
        if (r0*c0 != r*c) return mat;
        vector<int> v0(c);
        vector<vector<int>> v(r, v0);
        for (int i=0; i<r0*c0; ++i) v[i/c][i%c] = mat[i/c0][i%c0];
        return v;
    }
};
