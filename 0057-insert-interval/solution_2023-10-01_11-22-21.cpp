class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& in, vector<int>& newIn) {
        int n = in.size() , i=0;
        vector<vector<int>> vv;

        while(i<n and in[i][1]<newIn[0]) {
            vv.push_back(in[i++]);
        }

        while(i<n and in[i][0]<=newIn[1]){
            newIn[0]=min(newIn[0],in[i][0]);
            newIn[1]=max(newIn[1],in[i][1]);
            i++;
        }
        vv.push_back(newIn);

        while(i<n) vv.push_back(in[i++]);
        
        return vv;
    }
};
