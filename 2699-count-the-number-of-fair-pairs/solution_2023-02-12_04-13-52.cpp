class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(),nums.end());
            long long c=0;
            for(long long i=0; i<nums.size(); i++){
                long long x=lower-nums[i],y=upper-nums[i];
                long long l=lower_bound(nums.begin()+i+1,nums.end(),x)-nums.begin();
                long long u=upper_bound(nums.begin()+i+1,nums.end(),y)-nums.begin();
                if(l<=u) c+=u-l;
            }
        return c;
    }
};
