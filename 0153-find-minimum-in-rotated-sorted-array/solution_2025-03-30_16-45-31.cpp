class Solution {
public:
    int findMin(vector<int>& nums) {
        // if(nums.size()==1) return nums[0];
        if(nums.front() <= nums.back()) return nums[0]; 
        int n = nums.size();
        int left = 0; 
        int rgt = n-1;
        int mid;

        while(left<rgt){
            mid = left + ( rgt -left )/2;
            if(nums[mid]>nums[rgt]){
                left = mid+1;
            } else {
                rgt = mid;
            }
        }
        return nums[left];
    }
};
