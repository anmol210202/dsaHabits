class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        for(auto &e:nums) s.insert(e);
        int maxl=0;
        for(auto &e:nums){
            if(s.find(e-1)==s.end()){
                int tmpl=1;
                while(s.find(e+tmpl-1)!=s.end()){
                    tmpl++;
                    // cout<<e<<' ';
                }
                // cout<<endl;
                // cout<<tmpl<<' '<<endl;;
                maxl=max(maxl,tmpl-1);
            }
        }
        return maxl;
    }
};
