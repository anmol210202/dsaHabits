class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int can=0,c=0;
        for(auto &e:nums){
            if(c==0) can=e,c++;
            else if(e==can) c++;
            else c--;
        }
        // cout<<can<<c;
        c=0;
        for(auto &e:nums){
            if(e==can) c++;
            if(c>nums.size()/2) return e;
        }
        return -1;
    }
};
