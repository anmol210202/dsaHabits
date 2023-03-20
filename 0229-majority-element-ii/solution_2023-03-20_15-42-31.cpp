class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int> m;
        vector<int> v;
        for(auto &e:nums) m[e]++;
        int n=nums.size()/3;
        for(auto &e:m) if(e.second>n) v.push_back(e.first);
        return v;  
    }
};
