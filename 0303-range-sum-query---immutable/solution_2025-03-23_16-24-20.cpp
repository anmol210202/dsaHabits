class NumArray {

public:
    vector<int>& nums;

    NumArray(vector<int>& nums) : nums(nums) {
        int n = nums.size();
        // prefix.resize(n+1,0);
        for( int i=1; i<n; i++){
            nums[i]+=nums[i-1];
        }
    }
    
    int sumRange(int left, int right) {
        if (left == 0){
            return nums[right];
        }
        return nums[right]-nums[left-1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
