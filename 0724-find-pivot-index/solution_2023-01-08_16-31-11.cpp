class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        vector<int> l,r;
        int s=nums.size();
        l.push_back(nums[0]);
        r.push_back(nums[s-1]);
        for(int i=1; i<s; i++) l.push_back(nums[i]+l[i-1]);
        for(int i=s-2; i>=0; i--) r.push_back(nums[i]+r[s-i-2]);
        reverse(r.begin(),r.end());
        for(int i=0; i<s; i++)
        if(l[i]==r[i]) return i;
        return -1;
    }
};
