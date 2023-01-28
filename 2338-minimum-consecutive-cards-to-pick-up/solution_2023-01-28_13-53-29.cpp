class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        unordered_map<int,vector<int>> m;
        for(int i=0; i<cards.size(); i++) m[cards[i]].push_back(i);
        int mn=INT_MAX;
        for(auto &e:m) if(e.second.size()>1){
            for(int i=0; i<e.second.size()-1; i++){
                mn=min(mn,e.second[i+1]-e.second[i]+1);
            }
        }
        return mn==INT_MAX ? -1:mn;
    }
};
