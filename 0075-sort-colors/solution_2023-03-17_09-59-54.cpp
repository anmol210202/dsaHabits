class Solution {
public:
    void sortColors(vector<int>& nums) {
        int c1=0,c2=0,c3=0;
        for(auto &e:nums) if(e==0) c1++; else if(e==1) c2++; else c3++;
        for(auto &e:nums) if(c1!=0) e=0,c1--; else if(c2!=0) e=1,c2--; else e=2,c3--;
    }
};
