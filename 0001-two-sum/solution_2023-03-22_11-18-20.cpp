class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i=0,j=nums.size()-1;
        vector<pair<int,int>> vv;
        for(auto i=0; i<nums.size();i++) vv.push_back({nums[i],i});
        sort(vv.begin(),vv.end());
        vector<int> v;
        while(i<j){
            if(vv[i].first+vv[j].first==target){
                v.push_back(vv[i].second),v.push_back(vv[j].second);
                break;
            }
            else if(vv[i].first+vv[j].first>target) j--;
            else i++;
        }
        return v;
    }
};
