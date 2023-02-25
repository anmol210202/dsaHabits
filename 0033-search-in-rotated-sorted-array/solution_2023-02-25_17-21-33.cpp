class Solution {
public:
    int search(vector<int>& nums, int target) {
        int s=0,e=nums.size()-1,m=s+(e-s)/2;
        while(s<=e){
            if(nums[m]==target) return m;
            if(nums[m]>=nums[s]){
                if(nums[m]>=target and nums[s]<=target) e=--m;
                else s=++m;
            } else{
                if(nums[e]>=target and nums[m]<=target) s=++m;
                else e=--m;
            }
        }
        return -1;
    }
};
