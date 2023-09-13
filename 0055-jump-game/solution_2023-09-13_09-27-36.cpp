class Solution {
public:
    bool canJump(vector<int>& nums) {
        // greedy 
        int maxPosition = 0 , n=nums.size();
        for(int i=0 ; i<n; i++){
            maxPosition = max(maxPosition , i+nums[i]);
            if(maxPosition >= n-1) return true;
            if(i>=maxPosition) return false; 
        }
        return true;
    }
};
