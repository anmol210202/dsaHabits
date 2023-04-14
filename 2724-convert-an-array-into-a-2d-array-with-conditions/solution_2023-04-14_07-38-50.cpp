class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int,int> m;
        int mx=0;
        for(auto &e:nums){
            m[e]++;
            mx=max(m[e],mx);
        }
        cout<<mx<<endl;
        vector<vector<int>> v;
        while(mx--){
            vector<int> tmp;
            for(auto &e:m){
                if(e.second!=0){
                    tmp.push_back(e.first);
                    e.second--;
                }
            }
            v.push_back(tmp);
        }
        return v;
    }
};
