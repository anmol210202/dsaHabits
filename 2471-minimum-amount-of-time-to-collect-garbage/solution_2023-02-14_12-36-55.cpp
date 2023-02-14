class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        unordered_map<char,int> um;
        int a=0;
        for(int i=0; i<garbage.size(); i++) for(auto &s:garbage[i]) um[s]=i;
        for(int i=0; i<garbage.size(); i++) a+=garbage[i].size();
        for(int i=1; i<travel.size(); i++) travel[i]+=travel[i-1];
        for(auto &e:um) if(e.second != 0) a+=travel[e.second-1];
        return a;
    }
};
