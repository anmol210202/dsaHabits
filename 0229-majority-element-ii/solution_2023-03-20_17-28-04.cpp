class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> v;
        int n1=-69,n2=-69,c1=0,c2=0,n=nums.size()/3;
        for(auto &e:nums){
            if(n1==e) c1++;
            else if(n2==e) c2++;
            else if(c1==0) n1=e,c1=1;
            else if(c2==0) n2=e,c2=1;
            else c1--,c2--;
        }
        // cout<<c1<<' '<<c2<<' '<<n1<<' '<<n2;
        c1=c2=0;
        for(auto &e:nums){
            if(n1==e)c1++;
            if(n2==e)c2++;
        }
        if(c1>n) v.push_back(n1);
        if(c2>n) v.push_back(n2);
        return v;
    }
};
