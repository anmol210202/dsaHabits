class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int> m;
        for(int &e:nums){
            if(m.find(e) != m.end()) return true;
            m[e]++;
        }
        return false;
    }
};
