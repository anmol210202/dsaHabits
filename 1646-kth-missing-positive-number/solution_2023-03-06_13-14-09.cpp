class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        vector<int> v(10000,0),c;
        for(auto &e:arr) v[e]=1;
        for(int i=1; i<10000; i++) if(v[i]==0) c.push_back(i);
        // for(auto &e:c) cout<<e<<" ";
        // cout<<c.size()<<' '<<k;
        return c[k-1];
    }
};
