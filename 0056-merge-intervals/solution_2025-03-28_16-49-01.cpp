class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int n=intervals.size();
        
        if(n<1) return intervals;
        vector<vector<int>> merged(1,intervals[0]);

        for(int i=1; i<n; i++){
            if(merged.back()[1] >= intervals[i][0]){
                merged.back()[1]=(merged.back()[1] > intervals[i][1]) ? merged.back()[1]:intervals[i][1];
            } else{
                merged.push_back(intervals[i]);
            }
        }
        return merged;
    }
};
