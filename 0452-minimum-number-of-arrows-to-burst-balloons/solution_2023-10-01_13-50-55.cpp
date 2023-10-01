class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        int arrow = 1; 
        int c = points[0][1];

        for(auto &e:points){
            if(c==e[1]) continue; 
            if(c<e[0]){
                arrow++;
                c=e[1];
            } else {
                c = min(c,e[1]);
            }
        }

        return arrow;
    }
};
