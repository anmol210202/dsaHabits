class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> v;
        if(find(nums.begin(),nums.end(),target)==nums.end()){
            v.push_back(-1),v.push_back(-1);
            return v;
        }

        auto it = lower_bound(nums.begin(),nums.end(),target), it2=upper_bound(nums.begin(),nums.end(),target);
        int l=it-nums.begin(),u=it2-nums.begin()-1;
        v.push_back(l),v.push_back(u);
        return v;
    }
};
