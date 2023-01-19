class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int s=nums.size() , sum=0 , ans=0;;
        unordered_map<int,int> m;
        // for(int i=1; i<s; i++) nums[i]+=nums[i-1];
        m[0]++;
        for(auto &e:nums){
            sum+=e;
            int mod = (sum%k+k)%k;
            if(m.find(mod)!=m.end()) ans+=m[mod];
            m[mod]++;
        } 
        // return accumulate(m.begin(),m.end(),0,[](auto prev_Sum , auto &entry) {return prev_Sum +entry.second;});
        return ans;
    }
};
