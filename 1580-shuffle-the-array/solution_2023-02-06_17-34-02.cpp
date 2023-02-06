class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> v;
        int s=nums.size();
        for(int i=0; i<s/2; i++){
            v.push_back(nums[i]);
            v.push_back(nums[i+s/2]);
        }
        return v;
    }
};
