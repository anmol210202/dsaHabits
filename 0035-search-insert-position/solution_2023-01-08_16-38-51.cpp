class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0 , n = nums.size() , r=n-1 , m;
        while(l<=r){
            m = l+(r-l)/2;
            if(nums[m]==target) return m;
            if(nums[m]<target) l = m+1;
            else r=m-1;
        }
        return m==r ? m+1 : m;
    }
};
