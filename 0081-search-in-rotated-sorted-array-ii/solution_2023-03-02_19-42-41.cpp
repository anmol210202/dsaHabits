class Solution {
public:
    bool search(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        return count(nums.begin(),nums.end(),target)!=0;
    }
};
