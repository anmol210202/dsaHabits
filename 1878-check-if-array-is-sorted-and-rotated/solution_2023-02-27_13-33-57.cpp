class Solution {
public:
    bool check(vector<int>& nums) {
        int s=nums[0],n=nums.size(),x=0;
        for(int i=0; i<n;i++){
            if(i==n-1){ if(nums[i]>s) x++;}
            else {if(nums[i]>nums[i+1]) x++;}
        }
        // cout<<x<<endl;
        return x==1 or x==0 ?true:false;
    }
};
