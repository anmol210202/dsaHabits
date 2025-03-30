class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if(intervals.empty()) return 0;
        sort(intervals.begin(),intervals.end(),[](const vector<int>& a,const vector<int>& b){     // const to add unessary copies of vector 
            return a[1] < b[1];
        });
        int notOverlap = 1,end=intervals[0][1],n=intervals.size();
        
        for(auto i=1; i<n; i++){
            if(end <= intervals[i][0]){
                notOverlap++;
                end = intervals[i][1];
            }
        }

        return n-notOverlap;
    }
};
