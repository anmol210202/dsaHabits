class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> v;
        set<vector<int>> s;
        int n=nums.size()-1;
        for(int i=0; i<n-2; i++){
            for(int j=i+1; j<n-1; j++){
                long long newT = target -(long long)nums[i]-nums[j],k=j+1,l=n;
                // long long newT = target - (long long)nums[i] - nums[j];

                while(k<l){
                    if(nums[k]+nums[l]==newT){
                        s.insert({nums[i],nums[j],nums[k],nums[l]});
                        k++,l--;
                    }
                    else if(nums[k]+nums[l]>newT) l--;
                    else k++;
                }
            }
        }
        for(auto &e:s) v.push_back(e);
        return v;
    }
};
