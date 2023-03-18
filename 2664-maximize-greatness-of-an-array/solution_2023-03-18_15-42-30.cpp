#define forn(i,e) for(ll i = 0; i < e; i++)
#define sz(x) ((ll)(x).size())
typedef long long ll;
typedef vector<int> v32;
#define all(x) (x).begin(), (x).end()

class Solution {
public:
    int maximizeGreatness(vector<int>& nums) {
        int n=sz(nums);
        unordered_map<int,int> m;
        forn(i,n){
            m[nums[i]]++;
       }
       v32 temp=nums;
        sort(all(temp));
        int c=0;
        for(int i=0;i<n;i++){
            int req=nums[i]+1;
            bool f=false;
            while(lower_bound(temp.begin(),temp.end(),req)!=temp.end()){
                int idx=lower_bound(temp.begin(),temp.end(),req)-temp.begin();
                int t1=temp[idx];
                if(m[t1]>0){
                    c++;
                    m[t1]--;
                    break;
                }
                else{
                    req=t1+1;
                }
            }
        }
        return c;
        // vector<int> v(nums),tmp;
        // int n=nums.size();
        // sort(v.begin(),v.end());
        // for(int i=0; i<n; i++){
        //     auto it = upper_bound(v.begin(), v.end(), nums[i]);
        //     if (it != v.end()) {
        //         int up= distance(v.begin(), it);
        //         // cout<<up<<endl;
        //         tmp.push_back(v[up]);
        //         v.erase(v.begin()+up);
        //     }
        //     else{
        //         tmp.push_back(v[0]);
        //         v.erase(v.begin());
        //     }
        // }
        // // for(auto &e:tmp) cout<<e<<endl;
        // int c=0;
        // for(int i=0 ; i<n; i++){
        //     if(tmp[i]>nums[i]) c++;
        // }
        // return c;
    }
};
