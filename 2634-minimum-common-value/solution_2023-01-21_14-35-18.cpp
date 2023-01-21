class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> m;
        for(auto &e:nums1) m[e]++;
        for(auto &e:nums2)
            if(m.count(e)) return e;
        return -1;
    }
};
