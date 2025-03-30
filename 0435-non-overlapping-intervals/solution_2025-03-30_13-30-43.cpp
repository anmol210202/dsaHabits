class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),[](vector<int>& a,vector<int>& b){
            return a[1] < b[1];
        });

        int notOverlap = 1,end=intervals[0][1],n=intervals.size();
        
        for(int i=1; i<n; i++){
            if(end <= intervals[i][0]){
                notOverlap++;
                end = intervals[i][1];
            }
        }

        return n-notOverlap;
    }
};
