class Solution {
public:
    int waysToSplit(vector<int>& nums) {
        vector<int> v;
        int sum=0,n=nums.size(),ans=0,mod =1e9+7;
        for(auto &e:nums) sum+=e,v.push_back(sum);
        for(int i=0;i<n;i++){
           int low=lower_bound(v.begin()+i+1,v.end(),2*v[i])-v.begin();
           int up=upper_bound(v.begin()+i+1,v.begin()+n-1,v[i]+((v[n-1]-v[i])/2))-v.begin();
           ans+=(max(0,(up-low)))%mod;
           ans=ans%mod;
        }
        return ans;
        // for(int i=0; i<n-1; i++){
        //     // for(int j=i+2; j<n; j++){
        //     //     int l=v[i],m=v[j]-v[i]-nums[j],r=sum-v[j]+nums[j];
        //     //     // cout<<l<<' '<<m<<' '<<r<<endl;
        //     //     if(l<=m and m<=r) c++;
        //     // }
        //     int bi=i+2, be=n-1,bm=bi+(be-bi)/2,t=0;
        //     while(bi<=be){
        //         int l=v[i],m=v[bm]-v[i]-nums[bm],r=sum-v[bm]+nums[bm];
        //         if(l<=m and m<=r) bi=++m,t=m;
        //         else be=--m;
        //         bm=bi+(be-bi)/2;
        //     }
        //     c+=(t-bi);
        // }
        // return c;
    }
};
