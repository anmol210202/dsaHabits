class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(),nums.end());
        // for(auto &e:nums) s.insert(e);
        int maxl=0;
        for(auto &e:nums)
            if(s.find(e-1)==s.end()){
                int tmpl=1;
                while(s.find(e+tmpl)!=s.end()) tmpl++;
                maxl=max(maxl,tmpl);
            }
        return maxl;
    }
};
