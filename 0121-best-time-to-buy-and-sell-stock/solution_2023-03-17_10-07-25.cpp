class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mn = INT_MAX,a=0;
        for(auto &e:prices) mn=min(mn,e),a=max(a,e-mn);
        return a;
    }
};
