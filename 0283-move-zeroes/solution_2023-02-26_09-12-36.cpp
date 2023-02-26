class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i=0;
        for(auto &e:nums) if(e!=0) swap(e,nums[i]),i++;
    }
};
