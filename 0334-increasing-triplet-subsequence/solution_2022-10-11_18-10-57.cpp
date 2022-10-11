class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int a,b;
        a=b= INT_MAX;
        for(auto &e:nums){
            if(e<= a) a =e;
            else if(e<= b) b = e;
            else return true;
        }
        return false;
    }
};
