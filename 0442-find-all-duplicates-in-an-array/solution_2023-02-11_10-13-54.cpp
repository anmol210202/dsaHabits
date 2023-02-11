class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        unordered_map<int,int> m;
        for(auto &e:nums) m[e]++;
        nums.clear();
        for(auto &e:m) if(e.second!=1) nums.push_back(e.first);
        return nums;
    }
};
