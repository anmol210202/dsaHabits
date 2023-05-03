class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> v;
        set<int> s1,s2;
        for(auto &e:nums1) s1.insert(e);
        for(auto &e:nums2) s2.insert(e);
        vector<int> tmp;
        for(auto &e:s1) if(s2.find(e)==s2.end()) tmp.push_back(e);
        v.push_back(tmp);
        tmp.clear();
        for(auto &e:s2) if(s1.find(e)==s1.end()) tmp.push_back(e);
        v.push_back(tmp);
        tmp.clear();
        return v;
    }
};
