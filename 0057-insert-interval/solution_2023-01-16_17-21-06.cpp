class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<pair<int,bool>> v(100000,{0,false});
        vector<vector<int>> ans;
        for(auto &e:intervals){
            if(e[0]==e[1]) v[e[0]].second=true;
            v[e[0]].first+=1;
            v[e[1]].first+=-1;
        }

        v[newInterval[0]].first+=1;
        v[newInterval[1]].first+=-1;
        for(int i=1; i<100000; i++) {
            v[i].first+=v[i-1].first;
        }
        if(newInterval[0]==newInterval[1] and v[newInterval[0]].first==0){
            v[newInterval[0]].second=true;
            // for(int i=0; i<intervals.size(); i++){
            //     if(intervals[i][0]>newInterval[0]){
            //         intervals.insert(intervals.begin()+i,newInterval);
            //         return intervals;
            //     }
            // }
        }
        vector<int> tmp;
        if(v[0].first!=0 ) tmp.push_back(0);
        if(v[0].second and v[0].first==0) ans.push_back({0,0});
        for(int i=1; i<100000-1; i++) {
            if(v[i].second and v[i].first ==0 and v[i-1].first==0){
                ans.push_back({i ,i});
            }
            if(v[i-1].first==0 and v[i].first!=0) tmp.push_back(i);
            if(v[i-1].first!=0 and v[i].first==0){
                tmp.push_back(i);
                ans.push_back(tmp);
                tmp.clear();
            }
        }
        return ans;
    }
};
