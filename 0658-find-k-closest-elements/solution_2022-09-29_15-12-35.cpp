class Solution {
public:
    
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n=arr.size();
        vector<pair<int,int>> v;
        vector<int> ans;
        int m=0;
        int y=n;
        auto it =lower_bound(arr.begin(),arr.end(),x);
        if((it-arr.begin())+k>=n){
            y=n;
        } else {
            y=(it-arr.begin())+k+1;
        }
         if((it-arr.begin())-k<=n){
            m=0;
        } else{
             x=abs((it-arr.begin())-k);
         }
        
        for(int i=m; i<y; i++){
            pair<int,int> p;
            p.second = arr[i];
            p.first =abs(arr[i]-x);
            v.push_back(p);
        }
         sort(v.begin(), v.end());
        for(int i=0; i<k; i++){
            ans.push_back(v[i].second);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};
