class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int> s;
        for(auto &e:nums) s.insert(e);
        if(s.size()<3) return *--s.end();
        auto it = s.rbegin();
        advance(it,2);
        return *it;
        // return *next(s.rbegin(),2);
        // *--s.end() or *s.rbegin()      -------- s.end() return close to last itr
        // it = s.begin();
        //advance(it,2);
    }
};
