class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int s = nums.size();
        return (s+1)*s/2 -accumulate(nums.begin(), nums.end(), 0);
    }
};
