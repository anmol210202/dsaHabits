class Solution {
public:
    int DAC(vector<int>& nums , int s,int e){
        if(s>e) return INT_MIN;
        int ls= 0, rs=0;
        int mid=(s+e)/2;
        for(int i=mid-1, cs=0; i>=s; i--){
            cs+=nums[i];
            ls=max(cs,ls);
        }
        for(int i=mid+1, cs=0; i<=e;i++ ){
            cs+=nums[i];
            rs=max(cs,rs);
        }
        return max({DAC(nums,s,mid-1),DAC(nums,mid+1,e),ls+rs+nums[mid]});
    }
    
    int maxSubArray(vector<int>& nums) {
        return DAC(nums,0,size(nums)-1);
    }
};
