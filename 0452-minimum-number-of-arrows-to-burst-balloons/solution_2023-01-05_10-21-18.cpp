class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end());
        int ans = 1 , c=points[0][1];
        for(auto &e:points){
            if(e[1]==c) continue;
            if(c<e[0]){
                ans++;
                c=e[1];
            }
            else if(c>e[1]) c=e[1];
        }
        return ans;
    }
};
