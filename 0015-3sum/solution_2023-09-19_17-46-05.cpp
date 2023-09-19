class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> ans;
        set<vector<int>> sv;
        sort(nums.begin(),nums.end());
        for(int i=0; i<n; i++){
            int j=i+1, k=n-1;
            while(j<k){
                int sum= nums[i]+nums[j]+nums[k];
                if(sum==0){
                    // ans.push_back({nums[i],nums[j],nums[k]});
                    sv.insert({nums[i],nums[j],nums[k]});
                    k--,j++;
                }
                else if(sum>0) k--;
                else j++;
            }
        }
        
        for(auto &e:sv) ans.push_back(e);

        return ans;
    }
};
