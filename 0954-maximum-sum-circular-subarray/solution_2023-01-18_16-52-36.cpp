class Solution {
public:
    int algo(vector<int>& v){
        int mSF = INT_MIN , mEH = 0;
        for(auto &e:v){
            mEH+=e;
            if(mSF<mEH) mSF=mEH;
            if(mEH<0) mEH=0;
        }
        return mSF;
    }
    int maxSubarraySumCircular(vector<int>& nums) {
        int p=0, n=0;
        bool P=false, N=false;
        p = algo(nums);
        for(auto &e:nums){
            if(e<0) N=true;
            else{
                N=false;
                break;
            }
        }
        for(auto &e:nums){
            if(e>0) P=true;
            else{
                P=false;
                break;
            }
        }
        if(P) return accumulate(nums.begin(),nums.end(),0);
        if(N) return *max_element(nums.begin(),nums.end());
        for(auto &e:nums) e*=-1;
        n= accumulate(nums.begin(),nums.end(),0)*-1 + algo(nums);
        return max(p,n);
    }
};
