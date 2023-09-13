class Solution {
public:
    int jump(vector<int>& nums) {
        int maxReach =0, currEnd = 0, jumps=0,n=nums.size();
        if(n<2) return 0;
        for(int i=0; i<n; i++){
            maxReach = max(maxReach , nums[i]+i);
            if(i==currEnd){
                jumps++;
                currEnd=maxReach;
            }
            if(currEnd>=n-1) return jumps;
        }
        return jumps;
    }
};
