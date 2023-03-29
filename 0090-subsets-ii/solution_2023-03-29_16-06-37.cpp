class Solution {
public:
    void r(vector<int> &nums, int i,vector<int> tmp,set<vector<int>> &ans){
        if(i==nums.size()){
            ans.insert(tmp);
            return;
        }
        r(nums,i+1,tmp,ans);
        tmp.push_back(nums[i]);
        r(nums,i+1,tmp,ans);
        // tmp.pop_back();
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>> ans;
        vector<vector<int>> a;
        sort(nums.begin(),nums.end());
        vector<int> tmp;
        r(nums,0,tmp,ans);
        for(auto e:ans) a.push_back(e);
        return a;
    }
};
