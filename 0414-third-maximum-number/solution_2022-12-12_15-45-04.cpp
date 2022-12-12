class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int> s;
        for(auto &e:nums) s.insert(e);
        if(s.size()<3) return *--s.end();
        return *next(s.rbegin(),2);
    }
};
