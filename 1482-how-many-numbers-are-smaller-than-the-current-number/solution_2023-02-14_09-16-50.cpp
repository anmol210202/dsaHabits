class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> v(nums),ans;
        sort(v.begin(),v.end());
        for(auto &e:nums) ans.push_back(find(v.begin(),v.end(),e)-v.begin());
        return ans;
    }
};
