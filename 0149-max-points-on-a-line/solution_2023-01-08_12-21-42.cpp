class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        if(points.size()==1) return 1;
        map<double,int> m;
        int ans = 0;
        for(int i=0; i<points.size(); i++){
            m.clear();
            for(int j=0; j<points.size(); j++){
                if(i!=j){
                    if((points[i][0]-points[j][0])==0) m[INT_MAX]++; 
                    else m[(double)(points[i][1]-points[j][1])/(double)(points[i][0]-points[j][0])]++;
                }
            }
            // for(auto &e:m) cout<<e.first<<' '<<e.second<<endl;
            using pair_type = decltype(m)::value_type;
            auto s = max_element(begin(m), end(m),[] (const pair_type & p1, const pair_type & p2) { return p1.second < p2.second; })->second;
            cout<<s<<' '<<ans<<endl;
            ans = max(ans,s);
        }
        return ans+1;
        // map<pair<vector<int>,vector<int>>,int> m;
        // for(int i=0; i<points.size(); i++){
        //     for(int j=i+1; j<points.size(); j++){
        //         if((points[i][0]-points[j][0])==0) {m[{points[i],points[j]}]=INT_MAX; break;}
        //         m[{points[i],points[j]}]=(points[i][1]-points[j][1])/(points[i][0]-points[j][0]);
        //     }
        // }
        // for(auto &e:m) cout<<e.second<<endl;
        // map<int,int> c;
        // for(auto &e:m) c[e.second]++;
        // for(auto &e:c) cout<<e.first<<' '<<e.second<<endl;
        // using pair_type = decltype(c)::value_type;
        // auto s = max_element(begin(c), end(c),[] (const pair_type & p1, const pair_type & p2) { return p1.second < p2.second; })->first;
        // set<vector<int>> p;
        // for(auto &e:m){
        //     if(e.second==s){
        //         p.insert(e.first.first);
        //         p.insert(e.first.second);
        //     }
        // }
        // return p.size();
    }
};
