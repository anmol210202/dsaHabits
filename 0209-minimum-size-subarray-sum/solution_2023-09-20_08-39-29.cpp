class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int i,j,sum,minlen=2*n;
        i=j=sum=0;
        while(j<n){
            sum+=nums[j];
            while(sum>=target){
                minlen=min(minlen,j-i+1);
                sum-=nums[i];
                i++;
            }
            j++;
        }
        return i==0 ? 0:minlen;
    }
};
