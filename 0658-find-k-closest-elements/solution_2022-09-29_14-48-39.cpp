class Solution {
public:
    
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n=arr.size();
        vector<pair<int,int>> v;
        vector<int> ans;
        for(int i=0; i<n; i++){
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
