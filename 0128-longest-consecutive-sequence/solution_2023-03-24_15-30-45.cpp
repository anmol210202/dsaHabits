class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(),nums.end());
        int a=0;
        for(auto &e:nums){
            if(s.find(e-1)==s.end()){
                int tmp=1;
                while(s.find(e+tmp)!=s.end()) tmp++;
                a=max(a,tmp);
            }
        }
        return a;
    }
};
