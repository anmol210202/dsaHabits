class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int> m;
        for(auto &e:nums) m[e]++;
        for(auto &e:m) if(e.second==1) return e.first;
        return 0;
    }
};
