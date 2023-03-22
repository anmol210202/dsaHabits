class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long x=0,y=0;
        for(auto &e:nums) if(e==0) x+=++y; else y=0;
        return x;
    }
};   
