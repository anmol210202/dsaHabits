class Solution {
public:
    long long countSubarrays(vector<int>& nums, int mink, int maxk) {
        long long a=0,pmi=-1,pma=-1,j=-1;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]<mink or nums[i]>maxk) j=i;
            if(nums[i]==mink) pmi=i;
            if(nums[i]==maxk) pma=i;
            a += max(0, (int)(min(pmi,pma) - (int)j));
        }
        return a;
    }
};
