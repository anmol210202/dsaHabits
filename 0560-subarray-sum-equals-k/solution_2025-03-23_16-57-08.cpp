class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        int ans = 0;
        vector<int> prefix;
        prefix.resize(n+1,0);
        for(int i=0; i<n; i++){
            prefix[i+1]=prefix[i]+nums[i];
        }

        for(int i=0; i<n; i++){
            for (int j=i+1; j<=n; j++){
                if(prefix[j]-prefix[i]==k) ans++;
            }
        }
        return ans;
    }
};
