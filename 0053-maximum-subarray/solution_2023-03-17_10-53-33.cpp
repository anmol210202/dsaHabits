class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int msf=INT_MIN,meh=0;
        for(auto &e:nums){
            meh+=e;
            if(msf<meh) msf=meh;
            if(meh<0) meh=0;
        }
        return msf;
    }
};
