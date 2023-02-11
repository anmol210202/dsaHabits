class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> m,M;
        for(auto &e:arr) m[e]++;
        for(auto &e:m) M[e.second]++;
        return m.size()==M.size() ? true:false;
    }
};
